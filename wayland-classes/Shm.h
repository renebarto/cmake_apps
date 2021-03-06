#pragma once

#include <cstddef>

struct wl_shm;

namespace Wayland
{

class CursorTheme;

class Shm
{
public:
public:
    Shm(wl_shm * shm);
    ~Shm();

    void Cleanup();
    wl_shm * Get() const { return _shm; }

    CursorTheme * Load(const char *name, int size);

private:
    wl_shm * _shm;
};

} // namespace Wayland
