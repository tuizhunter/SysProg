# Willkommen zu SysProg im WS 16/17

## Organisation

Der Einfachheit halber kommen alle Lösungen in dieses Repo, statt für jedes Blatt ein eigenes Repo anzulegen. 
Bitte erstellt für jedes Übungsblatt und jede Aufgabe einen Ordner, so dass sich beispielsweise eine Ordnerstruktur BlattXX/AufgabeXX ergibt.  
Weiterhin würde ich mich freuen, wenn ihr darauf verzichtet Binärdateien oder irgendwelche Dateien eurer eventuell verwendeten IDE zum Repo hinzuzufügen.

## Tipps

* Falls ihr euren C Code debuggen wollt/müsst, ist neben 'gdb' auch 'rr' empfehlenswert, da dieser euch erlaubt die Ausführung aufzunehmen und dann wiederzugeben, 
so dass ihr auch rückwärts durch die Programmausführung steppen könnt.

* Wenn ihr zum Debuggen gdb benutzt, erhaltet ihr mit [dieser](https://github.com/gdbinit/Gdbinit) gdbinit Datei eine deutlich angenehmere Ausgabe als normal.  
Ihr könnt in der Datei auch noch einige Dinge modifizieren um beispielsweise immer einen Teil des Stacks angezeigt zu bekommen.

* [Hier](https://github.com/gdbinit/Gdbinit) finden sich eventuell noch einige interessante Informationen, wie man 'zeitgemäßes' C schreibt.

* Wenn ihr clang zum kompilieren benutzt, könnt ihr zum Auffinden von Speicherfehlern auch den [Address Sanitizer](http://clang.llvm.org/docs/AddressSanitizer.html) verwenden.
