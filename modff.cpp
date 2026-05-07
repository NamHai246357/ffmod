#include <substrate.h>
#include <mach-o/dyld.h>

// Offset giả định cho OB53 - Bạn có thể cập nhật khi có địa chỉ mới
uintptr_t get_head_offset() {
    return 0x1234567; // Đây là nơi bạn điền địa chỉ ghim tâm
}

void (*old_Update)(void* instance);
void new_Update(void* instance) {
    if (instance != NULL) {
        // Mã ghim tâm (Aimbot) và tăng vùng chạm (Hitbox)
        float *hitbox = (float*)((uintptr_t)instance + 0xABC); 
        if (hitbox) *hitbox = 3.0f; // Tăng hitbox lên 3 lần
    }
    old_Update(instance);
}

// Hàm nạp mod khi game khởi chạy
__attribute__((constructor))
static void initialize() {
    // Hook vào hàm xử lý của game
    MSHookFunction((void*)(_dyld_get_image_header(0) + get_head_offset()), (void*)new_Update, (void**)&old_Update);
}
