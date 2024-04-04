# Übung 1 - Lösung

## 1. Skip Lists (src/skiplist)

### Lösungsidee
Die SkipNode repräsentiert einen Knoten in der Skip-Liste. Jeder Knoten enthält Daten vom Typ T und einen Vektor von Zeigern auf die nächsten Knoten auf verschiedenen Ebenen.
Die skip_set Klasse ist die Hauptklasse, die die Skip-Liste repräsentiert. randomLevel()- diese Funktion generiert eine zufällige Ebene für einen neuen Knoten in der Skip-Liste.
void insert(T value) - Diese Methode fügt das neue Element an der richtigen Stelle ein, wobei darauf geachtet wird, dass die Liste korrekt sortiert bleibt und die Verknüpfungen entsprechend aktualisiert werden. Deshalb wird ein Vektor update erstellt, um die Knoten temporär zu speichern, und wird aktualisiert.
void erase(T value) - Diese Methode entfernt von der Skip-Liste das angegebene Element. Mit einer Schleife wird die Knoten auf der aktuellen Ebene durchläuft, bis entweder das Ende der Liste erreicht ist oder ein Knoten gefunden wird, dessen Daten größer oder gleich dem zu löschenden Wert sind. Der aktuelle Knoten wird im Vektor update für die aktuelle Ebene gespeichert. Das wird benötigt, um später die Verknüpfungen anzupassen und das zu löschende Element zu entfernen. Dann wird überprüft, ob das zu löschende Element in der Liste vorhanden ist. Die Verknüpfungen für das zu löschende Element auf allen Ebenen
werden aktualisiert, um es aus der Liste zu entfernen. Der Speicher für das zu löschende Element wird freigegeben.
Die Methode - bool find(T value) prüft, ob das angegebene Element in der Liste vorhanden ist. Sie gibt true zurück, wenn das Element gefunden wird, und false, wenn das Element nicht in der Liste vorhanden ist.

### Testfälle
```cpp
/Users/shahinm/Documents/SWE4/Ubung2/ue02-ulkerm/src/cmake-build-debug/bin/skiplist
Skip; List: 
Level 2: 2 3 
Level 1: 2 3 6 
Level 0: 2 3 5 6 8 

Is 5 in the set? true
Skip List after removal: 
Level 2: 2 3 
Level 1: 2 3 6 
Level 0: 2 3 6 8 

Is 5 in the set? false

Skip; List: 
Level 4: 7 
Level 3: 7 
Level 2: 1 7 12 26 
Level 1: 1 5 7 12 18 21 26 
Level 0: 0 1 3 5 7 9 10 12 13 18 19 21 26 

Is 7 in the set? true
Skip List after removal: 
Level 2: 1 12 26 
Level 1: 1 5 12 18 21 26 
Level 0: 0 1 3 5 9 10 12 13 18 19 21 26 

Is 7 in the set? false


```
