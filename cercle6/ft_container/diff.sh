#!/usr/bin
make re
mv ./ft_container ./ft_container_ft
make std
mv ./ft_container ./ft_container_std

echo "=================== std ==================="
basetime=$(date +%s%N)
./ft_container_std > std.txt
echo "runtime: $(echo "scale=5;($(date +%s%N) - ${basetime})/(1*10^09)" | bc) seconds"
echo "=================== ft ==================="
basetime=$(date +%s%N)
./ft_container_ft > ft.txt
echo "runtime: $(echo "scale=5;($(date +%s%N) - ${basetime})/(1*10^09)" | bc) seconds"


echo "=================== diff ==================="
diff --text std.txt ft.txt

#rm std.out ft.out ft_container_ft ft_container_std