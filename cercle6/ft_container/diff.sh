#!/bin/zsh
make re
mv ./ft_container ./ft_container_ft
make std
mv ./ft_container ./ft_container_std

echo "=================== std ==================="
time -p ./ft_container_std > std.out
echo "=================== ft ==================="
time -p ./ft_container_ft > ft.out

echo "=================== diff ==================="
diff std.out ft.out

rm std.out ft.out ft_container_ft ft_container_std