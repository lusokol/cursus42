make fclean
git clone https://github.com/Mazoise/42TESTERS-PRINTF.git
cd 42TESTERS-PRINTF/
bash runtest.sh
cd ..
git clone https://github.com/PandaCoustic-42/Test-42.git
make re
cp libftprintf.a Test-42/test_printf_classic/
cd Test-42/test_printf_classic/
make re
./ft_printf_tests
cd ../..
git clone https://github.com/gavinfielder/pft.git pft_2019 && echo "pft_2019/" >> .gitignore && cd pft_2019 && rm unit_tests.c && rm options-config.ini && git clone https://github.com/YulonSil/PFT_2019.git temp && cp temp/unit_tests.c . && cp temp/options-config.ini . && rm -rf temp
cd pft_2019/
make re
./test -k
cd ..
rm -rf 42TESTERS-PRINTF/ Test-42 pft_2019
