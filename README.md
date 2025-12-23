# 🎵 SPOTIKUY – Aplikasi Pemutar Musik Berbasis Konsol (C++)
---

## Deskripsi Proyek

Aplikasi pemutar musik ini berbasis **konsol** yang dikembangkan sebagai **Tugas Besar Mata Kuliah Struktur Data**. Dirancang untuk mengelola data lagu dalam jumlah banyak serta menyediakan fitur pemutaran musik dengan konsep yang sederhana namun terstruktur yang terinspirasi dari Spotify dalam versi sederhana. Aplikasi memiliki dua jenis peran pengguna, yaitu **Admin** dan **User**, yang masing-masing memiliki hak akses berbeda.

Aplikasi ini mampu mengelola data lagu, akun, dan playlist, serta menyediakan fitur pemutaran musik dengan mekanisme **next** dan **previous** lagu. 

Proyek ini dikembangkan sebagai implementasi konsep **Struktur Data**, khususnya:
- Singly Linked List (SLL)
- Doubly Linked List (DLL)
- Circular Doubly Linked List
- Multi Linked List (MLL)

---

## Role dan Hak Akses

**1. Admin**

  Admin memiliki hak akses penuh terhadap pengelolaan data lagu secara global.

  Fitur Admin:

  * Sign Up dan Login
  * Menambah data lagu
  * Menampilkan seluruh data lagu
  * Memperbarui data lagu
  * Menghapus data lagu

  Struktur data:
  * Akun Admin: Singly Linked List (SLL)
  * Data Lagu: Doubly Linked List (DLL)
  
  Setiap perubahan data lagu oleh Admin akan otomatis memengaruhi data yang ditampilkan kepada User.
  
  **2. User**
  
  User berperan sebagai pengguna aplikasi yang dapat menikmati dan mengelola musik sesuai preferensi.
  
  Fitur User:
  * Sign Up dan Login
  * Melihat seluruh lagu pada list lagu utama
  * Membuat playlist sendiri
  * Mengedit playlist milik sendiri (menambah dan menghapus lagu)
  * Mengikuti playlist milik User lain tanpa hak edit
  * Memutar lagu langsung dari list lagu utama
  * Memutar lagu berikutnya atau sebelumnya
    
  Struktur data:
  * Akun User: Singly Linked List (SLL)
  * Playlist: Doubly Linked List (DLL)
  * Relasi User–Playlist–Lagu: Multi Linked List (MLL)
  
  **🎧 Fitur Unggulan**
  * Manajemen lagu terpusat oleh Admin
  * Playlist dapat dibagikan dan diikuti oleh User lain
  * Pemutaran lagu berdasarkan genre terakhir
  * Relasi data kompleks namun terstruktur dengan baik
  
  Struktur Data yang Digunakan
  * **Singly Linked List (SLL)**: Digunakan untuk manajemen akun Admin dan User (Sign Up & Login)
  * **Doubly Linked List (DLL)**: Digunakan untuk pengelolaan data lagu utama dan playlist
  * **Circular Doubly Linked List (CDLL)**: Digunakan pada fitur pemutaran lagu (next & previous) agar pemutaran dapat berputar terus tanpa batas (looping)
  * **Multi Linked List (MLL)**: Digunakan untuk merepresentasikan relasi antara User, Playlist, dan Lagu

---

## ▶️ Cara Menjalankan Program
1. Pastikan semua file berada dalam satu folder:
   - `main.cpp`
   - `app.cpp`
   - `backend.cpp`
   - `app.h`
   - `backend.h`

2. Compile program menggunakan  g++:
```bash
g++ main.cpp app.cpp backend.cpp -o spotikuy
```
---

### Tim Pengembang
* **Rosandi Setiano** (103052400028)
* **Syauqi Gathan Setyapratama** (103052400051)
* **Nada Thahira Sosa** (103052400049)

Program Studi **S1 Sains Data**
Fakultas Informatika – Universitas Telkom
2025
