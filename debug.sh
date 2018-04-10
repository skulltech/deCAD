rm -rf bin
make
cp *.txt bin
cd bin

echo "[*] Running."
./deCAD $1 $2
cd ..
