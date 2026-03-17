content = """ HƯỚNG DẪN CÀI ĐẶT VÀ CHẠY C++ TRÊN VSCODE
==========================================

Bước 1: Cài đặt Vscode
------------------
- Vào https://code.visualstudio.com
- Tải bản  Windows
- cài đặt bình thường (Next -> Next -> Finish)


Bước 2: Cài Extension C++
--------------------------
1. Mở Vscode
2. Nhấn Ctrl + Shift + X (mở  Extensions)
3. Tìm "C/C++" -> chọn cái của Microsoft -> nhấn Install


Bước 3: Cài MINGW (compiler g++)
---------------------------------
1. Vào https://www.msys2.org
2. Tải file .exe -> cài đặt mặc định
3. Sau khi cài xong, mở cửa sổ MSYS2 UCRT64 (timf trong Start Menu)
4. Chạy lệnh sau trong MSYS2:
   pacman -S --mingw-w64-ucrt-x86_64-gcc
5. Nhấn y để xác nhận cài đặt


Bước 4: Thêm G++ vào ENVIRONMENT VARIABLES
-------------------------------------------
1. Nhấn phím Windows -> tìm "Edit the system environment variables" -> mở ra
2. Nhấn nút "Environment Variables..."
3. Ở phần  "System variables" -> tìm dòng  "Path" -> nhấn "Edit"
4. Nhấn "New" -> thêm vào: C:\msys64\ucrt64\bin
5. Nhấn OK -> OK -> OK để lưu


Bước 5: Kiểm tra cài đặt thành công
-------------------------------------
1. Mở Command Prompt (nhan Windows + R -> gõ "cmd" -> Enter)
2. Gõ lệnh: g++ --version
3. Nếu hiện ra số phiên bản (VD: g++ 15.2.0) -> Cài thành công!
  Nếu báo "not recognized" ->Kiểm tra lại bước 4


BUOC 6: Tạo File tasks.json (để tự động bulid)
-----------------------------------------------
1. Mở VSCode -> mở thư mục chứa file .cpp
2. tạo thư mục ".vscode" trong project (nếu chưa có)
3. Tạo file "tasks.json" trong thư mục .vscode với nội dung:
```
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "build",
      "type": "shell",
      "command": "g++",
      "args": [
        "${file}",
        "-o",
        "${fileDirname}\\${fileBasenameNoExtension}.exe"
      ],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "problemMatcher": ["$gcc"]
    }
  ]
}
```

Bước 7: Tạo file launch.json (để tự động chạy/debug)
------------------------------------------------------
Tạo file "launch.json" trong thư mục .vscode với nội dung:
```
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "C/C++ Debug",
      "type": "cppdbg",
      "request": "launch",
      "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${fileDirname}",
      "externalConsole": true,
      "preLaunchTask": "build",
      "MIMode": "gdb",
      "miDebuggerPath": "gdb",
      "setupCommands": [
        {
          "description": "Enable pretty-printing for gdb",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
        }
      ]
    }
  ]
}
```

Bước 8: Chạy chương trình lần đầu
-----------------------------------
1. Mở file .cpp cần chạy trong VSCode
2. Nhấn F5
3. VSCode sẽ tự động:
   - Compile file .cpp -> tao ra file .exe cùng tên
   - Mở cửa sổ console đến và chạy chương trinh
4. Nếu thành công -> cửa sổ console hiển thị kết quả chương trình
5. Nếu thất bại -> terminal hiện thông báo màu đỏ