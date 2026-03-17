content = """HUONG DAN CAI DAT VA CHAY C++ TREN VSCODE
==========================================

BUOC 1: CAI VSCODE
------------------
- Vao https://code.visualstudio.com
- Tai ban Windows
- Cai dat binh thuong (Next -> Next -> Finish)


BUOC 2: CAI EXTENSION C++
--------------------------
1. Mo VSCode
2. Nhan Ctrl + Shift + X (mo Extensions)
3. Tim "C/C++" -> chon cai cua Microsoft -> nhan Install


BUOC 3: CAI MINGW (compiler g++)
---------------------------------
1. Vao https://www.msys2.org
2. Tai file .exe -> cai dat mac dinh
3. Sau khi cai xong, mo cua so MSYS2 UCRT64 (tim trong Start Menu)
4. Chay lenh sau trong MSYS2:
   pacman -S --mingw-w64-ucrt-x86_64-gcc
5. Nhan Y de xac nhan cai dat


BUOC 4: THEM G++ VAO ENVIRONMENT VARIABLES
-------------------------------------------
1. Nhan phim Windows -> tim "Edit the system environment variables" -> mo ra
2. Nhan nut "Environment Variables..."
3. O phan "System variables" -> tim dong "Path" -> nhan "Edit"
4. Nhan "New" -> them vao: C:\msys64\ucrt64\bin
5. Nhan OK -> OK -> OK de luu


BUOC 5: KIEM TRA CAI DAT THANH CONG
-------------------------------------
1. Mo Command Prompt (nhan Windows + R -> go "cmd" -> Enter)
2. Go lenh: g++ --version
3. Neu hien ra so phien ban (vi du: g++ 15.2.0) -> cai thanh cong!
   Neu bao "not recognized" -> kiem tra lai Buoc 4


BUOC 6: TAO FILE tasks.json (de tu dong build)
-----------------------------------------------
1. Mo VSCode -> mo thu muc chua file .cpp
2. Tao thu muc ".vscode" trong project (neu chua co)
3. Tao file "tasks.json" trong thu muc .vscode voi noi dung:
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

BUOC 7: TAO FILE launch.json (de tu dong chay/debug)
------------------------------------------------------
Tao file "launch.json" trong thu muc .vscode voi noi dung:
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

BUOC 8: CHAY CHUONG TRINH LAN DAU
-----------------------------------
1. Mo file .cpp can chay trong VSCode
2. Nhan F5
3. VSCode se tu dong:
   - Compile file .cpp -> tao ra file .exe cung ten
   - Mo cua so console den va chay chuong trinh
4. Neu thanh cong -> cua so console hien ket qua chuong trinh
5. Neu that bai -> terminal hien thong bao loi mau do
