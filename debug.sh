rm -rf bin
make
cp 2Dinput.txt bin
cp 3Dinput.txt bin

cd bin

echo "[*] Running."
./deCAD
cd ..
