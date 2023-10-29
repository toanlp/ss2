#include <iostream>
#include <string>

#define SET_NAME() \
    void set_name(std::string name) { name_ = name; }
#define GET_NAME() \
    std::string get_name() { return name_; }

// Base class definition
class BaseImg
{
protected:
    std::string name_;

public:
    SET_NAME();
    GET_NAME();
    virtual std::string open(std::string data_path) = 0;
};
// Derived class PngppImg
class PngppImg : public BaseImg
{
public:
    std::string open(std::string data_path) override
    {
        // Implementation specific to PngppImg
        return "PngppImg: Opening image at " + data_path;
    }
};
// Derived class LodepngImg
class LodepngImg : public BaseImg
{
public:
    std::string open(std::string data_path) override
    {
        // Implementation specific to LodepngImg
        return "LodepngImg: Opening image at " + data_path;
    }
};
// Template class BaseImg
template <class T>
class BaseImgTemplate
{
private:
    T image_;

public:
    std::string open(std::string data_path)
    {
        std::cout << "open BaseimgTemplate" << std::endl;
        return image_.open(data_path);
    }
};
int main()
{
    std::string data_path = "linux_test.png";
    // Create instances of derived classes
    PngppImg pngpp_img;
    LodepngImg lodepng_img;
    // Set names using base class methods
    pngpp_img.set_name("Pngpp Image");
    lodepng_img.set_name("Lodepng Image");

    // Polymorphic call using template
    BaseImgTemplate<PngppImg> pngpp_i;
    BaseImgTemplate<LodepngImg> lodepng_i;

    std::cout << "Using derived class objects:" << std::endl;
    std::cout << pngpp_img.open(data_path) << std::endl;
    std::cout << lodepng_img.open(data_path) << std::endl;

    std::cout << "Using template class objects:" << std::endl;
    std::cout << pngpp_i.open(data_path) << std::endl;
    std::cout << lodepng_i.open(data_path) << std::endl;

    std::cout << "Names of the images:" << std::endl;
    std::cout << pngpp_img.get_name() << std::endl;
    std::cout << lodepng_img.get_name() << std::endl;

    return 0;
}