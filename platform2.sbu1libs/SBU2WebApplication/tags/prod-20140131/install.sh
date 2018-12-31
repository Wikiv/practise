export install_dir=/usr/local/include/sbu2webapp/
test -d install_dir || rm $install_dir -R 
mkdir $install_dir
cp include/* $install_dir/
cp bin/libsbu2webapp++.so /usr/local/lib/
ldconfig /usr/local/lib/
