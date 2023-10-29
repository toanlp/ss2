#include <iostream>
#include <string>
using namespace std;
#define SET_NAME() \
    void set_name(string name) { name_ = name; }
#define GET_NAME() \
    string get_name() { return name_; }
class BaseImg
{
public:
    std::string name_;
    SET_NAME();
    GET_NAME();
    string open(string image_path)
    {
        cout << "open image by Base IMG" << endl;
    }
};
class PngppImg : public BaseImg
{
public:
    bool open_image(string image_path)
    {
        cout << "open image by PngppImg" << endl;
    }
};
class Lodepng : public BaseImg
{
    bool open_image(string image_path)
    {
        cout << "open image by Lodepng" << endl;
    }
};
class BaseImgTemplate
