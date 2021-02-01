#!/bin/bash
set -eux

######################################
#               Colors               #
######################################

_BLUE='\033[34m'
_GREEN='\033[32m'

######################################
#       Lancement de minikube        #
######################################

minikube delete
#minikube start --vm-driver=docker
minikube start --vm-driver=virtualbox

#        snap install minikube
#        brew install minikube

######################################
#  Assignation de l'ip de minikube   #
######################################

#export MINI=$(minikube ip)
export MINI=$(minikube ip | grep -oE "\b([0-9]{1,3}\.){3}\b")20

cp srcs/metallb/metallb-conf-copy.yaml srcs/metallb/metallb-conf.yaml
sed -ie "s/MYIP/$MINI/g" ./srcs/metallb/metallb-conf.yaml

######################################
# Configure metallb as load-balancer #
######################################

printf "\e[93mInstalling metallb...\e[0m\n"
#kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
#kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml 
#kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)" 
minikube addons enable metallb

kubectl apply -f srcs/metallb/metallb-conf.yaml

#kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
#kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml 
#kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)" 

#kubectl apply -f srcs/metallb/metallb-conf.yaml 

######################################
#            Docker Build            #
######################################
sleep 5
eval $(minikube docker-env)

printf "\e[93mBuilding Nginx...\e[0m\n"
docker build -t my_nginx srcs/nginx/
printf "\e[93mBuilding WordPress...\e[0m\n"
docker build -t my_wordpress srcs/wordpress/

eval $(minikube docker-env --unset)

######################################
#          Config YAML               #
######################################

printf "\e[34mDeployement NGINX...\e[0m\n"
kubectl apply -f srcs/nginx/nginx-deployment.yaml
printf "\e[34mDeployement WORDPRESS...\e[0m\n"
kubectl apply -f srcs/wordpress/my_wordpress.yaml

###
printf "\n\n
\e[38;5;196m███████╗████████╗     ███████╗███████╗██████╗ ██╗   ██╗██╗ ██████╗███████╗███████╗
\e[38;5;208m██╔════╝╚══██╔══╝     ██╔════╝██╔════╝██╔══██╗██║   ██║██║██╔════╝██╔════╝██╔════╝
\e[38;5;226m█████╗     ██║        ███████╗█████╗  ██████╔╝██║   ██║██║██║     █████╗  ███████╗
\e[38;5;118m██╔══╝     ██║        ╚════██║██╔══╝  ██╔══██╗╚██╗ ██╔╝██║██║     ██╔══╝  ╚════██║
\e[38;5;87m██║        ██║███████╗███████║███████╗██║  ██║ ╚████╔╝ ██║╚██████╗███████╗███████║
\e[38;5;164m╚═╝        ╚═╝╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝  ╚═══╝  ╚═╝ ╚═════╝╚══════╝╚══════╝\e[0m
                                                                                  \n\n"
######################################
#         Minikube Dashboard         #
######################################

minikube dashboard