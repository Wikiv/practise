#IN="SBU2WebApplication;ubacGzip;ubacHTTPClient;ubacIPC;ubacJSONParser;ubacLogger;ubacLZO;ubacMemcache;ubacMSSQL;ubacMySQL;ubacpushlib;ubacSSLInterface;ubacTALib;ubacUtils;ubacXML;ubacYAML"

#IN="ubacUtils;ubacSSLInterface;ubacIPC;ubacYAML;ubacLogger;ubacHTTPClient;ubacXML;ubacMySQL;ubacJSONParser;ubacTALib;ubacpushlib;SBU2WebApplication"
IN="ubacUtils;ubacSSLInterface;ubacIPC;"
OIFS=$IFS
IFS=';'
arr2=$IN
for x in $arr2
do
    echo "> [$x]"
    cd $x/trunk
    make clean; make -j4;  
    rc=$?
    if [[ $rc != 0 ]]
	then exit $rc
    fi
    sudo make install;
    cd ../..
done

