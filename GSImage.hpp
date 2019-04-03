// GSImage.hpp

#include <vector>
#include <stdint.h>

class GSImage {
  public:
    GSImage(char const* filename);
    GSImage(int w, int h);

    void save_png(char const* filename);
    auto pixels() { return pixels_.data(); }
	auto pixels255() { return pixels255_.data(); }
    auto pixels() const { return pixels_.data(); }
    auto w() const { return w_; }
    auto h() const { return h_; }

    class View {
        public:
            auto operator[](int r) {
                        return image.pixels() + (y + r) * image.w() + x;
                    }        
    
            int x;
            int y;
            int w;
            int h;
            GSImage& image;
        };

    auto view(int x, int y, int w, int h) {
            return View { x, y, w, h, *this };
        }

  private:
    std::vector<float> pixels_;
    int w_;
    int h_;
	std::vector<float> pixels255_;
};
