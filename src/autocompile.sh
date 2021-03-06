md5sum *.cpp *.h > checksum/OldCheck.txt

if diff "checksum/OldCheck.txt" "checksum/sumfile.txt" > /dev/null; then

    echo
    echo Same Files
    echo

else

md5sum *.cpp *.h > checksum/sumfile.txt

    echo
    echo Compiling...B
    echo

    time g++ -std=c++17 -g -pthread -fpermissive *.cpp -o Displayout # compile
    mv Displayout ../
fi

if [ $? -ne 0 ]
then

    echo
    echo "Compile failed!"
    echo
    exit 1

fi

md5sum *.cpp *.h > checksum/sumfile.txt

    echo
    echo Running...
    echo

    cd ..

    time ./Displayout # --DEBUG_INFO # run

    echo
    echo Done!
    echo
