# CPP

（Rosseta 2 は速い）
Apple silicon M1 は　TSMC 5nm /  160億トランジスタ / 119mm^2 で製造されている。 four high-performance Firestorm and four energy-efficient Icestorm cores を持つ。
firestorm core は　 8-wide decode out-of-order である。
intel X86 の store 命令である MOV は in-order で実行される。対して ARMv8 の STR 命令は out-of-order である。ARMv8 は Aqure Release semantics で設計されており STRL store register reLease と  LDRA load register acquire を持つ。つまり x86 MOV は ARMv8 STR　には翻訳できない。
そこで apple silicon M1 ではハードウェア的に STR が in-order で実行されるモード（＝intel互換モード）を実装した。

（Acquire Release Semantics について）

(RCsc maintains sequential consistency among special operations)
All operations following an acquire in program order also following it in global memory order

All operations preceding a release in program order also precede it in global memory order

A release that precedes an acquire in program order also precedes it in global memory order


store release = git push  、  load acquire = git pull というアナロジーは有用である。

store release 　STRL で書き出され  load acquire　LDRA で読みだされる「フラッグ」は  git の header に相当し、それ以外で  store / load されるものはデータ（ファイル）に相当する。
ファイルを編集（変更）した結果がすべて repository に書き込んだ上で header を更新するのが git push  である。
header を読み取り、ファイルの変更を repository から読み出すのが git pull である。
git pull した情報は header 情報に対して consistent である。最新ではなくても、 consistent であることが重要。

(Reference)

RISC-V Weak Memory Ordering (“RVWMO”)
Dan Lustig

https://riscv.org/wp-content/uploads/2018/05/14.25-15.00-RISCVMemoryModelTutorial.pdf

（References）

C/C++11 mappings to processors 
https://www.cl.cam.ac.uk/~pes20/cpp/cpp0xmappings.html

x86 (including x86-64)
Load Relaxed:	MOV (from memory)
Load Acquire:	MOV (from memory)
Store Relaxed:	MOV (into memory)
Store Release:	MOV (into memory)

AArch64
Load Relaxed:	LDR
Load Acquire:	LDAR
Store Relaxed:	STR
Store Release:	STLR

（References）

https://arxiv.org/pdf/1803.04432.pdf
Memory Models for C/C++ Programmers
Manuel P¨oter
Jesper Larsson Tr¨af

（References）

https://preshing.com/20120913/acquire-and-release-semantics/
Acquire and Release Semantics

（memo）
cross compiler
$ arm-linux-gnueabihf-gcc -o hello_arm hello.c 
