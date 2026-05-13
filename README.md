<div align="center">
  <h1> ⚙️ libasm
  </h1>
</div>

<div align="center">
   <img width="200" height="170" alt="Screenshot from 2026-05-13 16-33-02" src="https://github.com/user-attachments/assets/21abc416-1dfe-4623-9464-8553cf92c1c7" />
" />
</div>

---

libasm is a 42 project that introduce us & become familiar to assembly language.

This library is a first step towards assembly & low-level programming.

![Static Badge](https://img.shields.io/badge/os-linux-orange)
![Static Badge](https://img.shields.io/badge/language-asm-red)

## Run Locally

Clone the project

```bash
  git clone https://github.com/drabiot/libasm.git
```

Go to the project directory

```bash
  cd libasm
```

Compile the project

```bash
  //To compile the library
  make -j

  //To compile the library & the tester
  make tester -j
````

Test the project

```bash
  make tester -j && ./tester
```


## Documentation

#### Mandatory

The Goal of the project is to redo small function in assembly & test them.
There is a total of 5 Mandatory fucntion to redo:
- ft_strlen (man 3 strlen)
- ft_strcpy (man 3 strcpy)
- ft_strcmp (man 3 strcmp)
- ft_write (man 2 write)
- ft_read (man 2 read)
- ft_strdup (man 3 strdup)


There are some rules:
- set errno variable correctly
- write in 64-bit assembly
- no inline ASM
- must use the Intel syntax, not the AT&T syntax


## Sources

- Learn Assembly https://www.tutorialspoint.com/assembly_programming/assembly_introduction.htm
- Learn Registers https://www.cs.uaf.edu/2017/fall/cs301/lecture/09_11_registers.html
- Diff between Intel & AT&T https://medium.com/@irfanbhat3/intel-vs-at-t-syntax-426fb7a78c96
- Coding Read / Write https://www.chromium.org/chromium-os/developer-library/reference/linux-constants/syscalls/
- https://man7.org/linux/man-pages/man2/
- https://www.felixcloutier.com/x86/
- Malloc for strdup https://www.cs.uaf.edu/2010/fall/cs301/lecture/10_04_malloc.html
- https://adonis0147.github.io/post/hello_x86_64_assembly/
- https://www.gladir.com/LEXIQUE/ASM/call.htm
