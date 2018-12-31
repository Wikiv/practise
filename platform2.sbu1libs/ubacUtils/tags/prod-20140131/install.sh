export install_dir=/usr/local/include/ubacutils/
test -d $install_dir ||  mkdir $install_dir
cp include/* $install_dir/
cp bin/* /usr/local/lib/
ldconfig /usr/local/lib/

