# so_long - Makefile Kullanım Kılavuzu

## 📁 Proje Yapısı

```
so_long/
├── Makefile          # Ana build dosyası
├── includes/         # Header dosyaları (.h)
│   └── so_long.h
├── src/              # Kaynak kodları (.c)
│   ├── main.c
│   └── game_init.c
├── obj/              # Derlenmiş object dosyaları (otomatik oluşur)
├── mlx_linux/        # MinilibX kütüphanesi
└── so_long           # Çalıştırılabilir dosya (make sonrası)
```

## 🔧 Makefile Komutları

### 1. Projeyi Derlemek
```bash
make
```
veya
```bash
make all
```
Bu komut:
- MinilibX'i derler (`mlx_linux/libmlx.a` oluşturur)
- libft'yi derler (`../libft/libft.a` kullanır)
- ft_printf'i derler (`../ft_printf/libftprintf.a` kullanır)
- Tüm `.c` dosyalarını derler ve `obj/` klasörüne `.o` dosyaları oluşturur
- Hepsini birleştirip `so_long` çalıştırılabilir dosyasını oluşturur

### 2. Object Dosyalarını Temizlemek
```bash
make clean
```
- `obj/` klasörünü siler
- libft, ft_printf ve mlx_linux'teki object dosyalarını temizler
- `so_long` çalıştırılabilir dosyasını **silmez**

### 3. Her Şeyi Temizlemek
```bash
make fclean
```
- `make clean` yapar
- `so_long` çalıştırılabilir dosyasını siler
- libft ve ft_printf'in `.a` dosyalarını siler
- Projeyi temiz hale getirir

### 4. Yeniden Derlemek
```bash
make re
```
- `make fclean` yapar
- Ardından `make all` yapar
- Her şeyi sıfırdan derler

## 📝 Yeni Kaynak Dosya Eklemek

`Makefile`'da `SRCS` değişkenine yeni dosyanızı ekleyin:

```makefile
SRCS = main.c \
       game_init.c \
       yeni_dosya.c \        # Yeni dosyanız
       baska_dosya.c         # Başka bir dosya
```

**Not:** Dosya yollarını değil, sadece dosya isimlerini yazın. Dosyalar `src/` klasöründe olmalı.

## 🎯 MinilibX Entegrasyonu Nasıl Çalışır?

### 1. **MinilibX Derleniyor**
```makefile
$(MLX_LIB):
    make -C $(MLX_DIR)
```
- `make -C mlx_linux` komutu mlx_linux klasörüne gidip oradaki Makefile'ı çalıştırır
- `libmlx.a` dosyası oluşur

### 2. **Header Dosyaları İçe Aktarılıyor**
```makefile
INCLUDES = -I includes -I mlx_linux -I ../libft -I ../ft_printf
```
- `-I mlx_linux` compiler'a `mlx.h`'yi `mlx_linux/` klasöründe aramasını söyler
- Kodunuzda `#include "../mlx_linux/mlx.h"` veya `#include "mlx.h"` yazabilirsiniz

### 3. **Kütüphane Linkleniyor**
```makefile
MLX_FLAGS = -L mlx_linux -lmlx -lXext -lX11 -lm

$(NAME): $(OBJS)
    $(CC) $(OBJS) $(MLX_FLAGS) $(LIBFT) $(FT_PRINTF) -o $(NAME)
```
- `-L mlx_linux`: Kütüphaneyi `mlx_linux/` klasöründe ara
- `-lmlx`: `libmlx.a` dosyasını linkle
- `-lXext -lX11`: X11 window sistem kütüphanelerini linkle (Linux için gerekli)
- `-lm`: Math kütüphanesini linkle

## 🔍 Önemli Değişkenler

```makefile
NAME        = so_long              # Program adı
CC          = cc                   # Compiler (gcc yerine cc 42'de)
CFLAGS      = -Wall -Wextra -Werror -g  # Compile bayrakları
SRC_DIR     = src                  # Kaynak kodların klasörü
OBJ_DIR     = obj                  # Object dosyalarının klasörü
MLX_DIR     = mlx_linux           # MinilibX klasörü
LIBFT_DIR   = ../libft            # libft klasörü
FT_PRINTF_DIR = ../ft_printf      # ft_printf klasörü
```

## ✅ Makefile'ın Çalışma Sırası

1. **`make` komutu çalıştırılır**
2. **MinilibX derler** → `mlx_linux/libmlx.a`
3. **libft derler** → `../libft/libft.a`
4. **ft_printf derler** → `../ft_printf/libftprintf.a`
5. **Her `.c` dosyası derlenir** → `obj/dosya.o`
6. **Tüm object dosyaları ve kütüphaneler linklenir** → `so_long`
7. **✓ so_long created successfully!**

## 🚀 Hızlı Test

```bash
make                    # Derle
./so_long maps/map.ber  # Çalıştır (map dosyanızla)
make fclean            # Temizle
```

## 💡 İpuçları

- **Hata aldıysanız:** `make fclean && make` yapın
- **MinilibX güncellemek için:** `cd mlx_linux && make re && cd ..`
- **Sadece bir dosyayı değiştirdiyseniz:** `make` yeterli (sadece değişen dosyayı derler)
- **Valgrind ile test:** `valgrind --leak-check=full ./so_long maps/map.ber`

## 📦 Gereksinimler

Sisteminizde olması gerekenler:
```bash
# Ubuntu/Debian
sudo apt-get install gcc make xorg libxext-dev libbsd-dev

# Fedora
sudo dnf install gcc make xorg-x11-server-Xorg libXext-devel libbsd-devel
```

---
**Not:** Bu Makefile 42 kurallarına uygun şekilde hazırlanmıştır. Norminette uyumlu değildir çünkü Makefile'lar norminette kontrol edilmez.
