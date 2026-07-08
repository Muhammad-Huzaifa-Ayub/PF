#include<iostream>
#include<fstream>


using namespace std;


int main(){

    fstream file("sample.bmp", ios :: binary | ios :: in | ios :: out);

    if (!file)
    {
        cout << "File not found." << endl;
        exit(0);
    }

    int width, height;

    file.seekg(18);
    file.read((char *)&width,sizeof(width));

    file.seekg(22);
    file.read((char*)&height, sizeof(height));

    cout << " the original width is : " << width << endl;
    cout << " the original height is : " << height << endl;

    height = height / 2;

    file.seekp(22);
    file.write((char*)&height, sizeof(height));

    cout << " the height after / 2 is : " << height << endl;
    
    file.close();

    return 0;
}
