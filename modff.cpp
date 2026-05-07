#include <iostream>

// Hàm khởi tạo để hệ thống nhận diện file mod
__attribute__((constructor))
static void initialize() {
    std::cout << "Mod Free Fire OB53 Loaded!" << std::endl;
}

// Các tính năng cho anh em mình quảng cáo với khách
extern "C" float GetHitbox() { return 3.5f; }
extern "C" bool AutoAim() { return true; }
