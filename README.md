# CPP

store release = git push  、  load acquire = git pull というアナロジーは有用である。

store release 　STRL で書き出され  load acquire　LDRA で読みだされる「フラッグ」は  git の header に相当し、それ以外で  store / load されるものはデータ（ファイル）に相当する。
ファイルを編集（変更）した結果がすべて repository に書き込んだ上で header を更新するのが git push  である。
header を読み取り、ファイルの変更を repository から読み出すのが git pull である。
git pull した情報は header 情報に対して consistent である。最新ではなくても、 consistent であることが重要。


References
https://arxiv.org/pdf/1803.04432.pdf
Memory Models for C/C++ Programmers
Manuel P¨oter
Jesper Larsson Tr¨af

https://preshing.com/20120913/acquire-and-release-semantics/
Acquire and Release Semantics
