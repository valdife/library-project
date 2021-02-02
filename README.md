# library-project
My C project intended for studies.

[PL]

Program Biblioteka pozwala na wykonanie pięciu różnych
operacji:

1. Wyświetlenia wszystkich posiadanych książek w
bibliotece.
2. Znalezienia ceny najstarszej książki w księgozbiorze.
Jeżeli takich jest więcej, wypisze ich średnią cenę.
3. Wprowadzenie nazwy autora, dla którego zostaną
wypisane jego wszystkie książki.
4. Wyświetlenie listy lat, z których posiadane książki
pochodzą (od najstarszego roku do najmłodszego). Przy
każdym roku zostaną wylistowane książki, które z tego
roku pochodzą.
5. Wyświetlenie listy autorów, których książki istnieją w
księgozbiorze. Dla każdego autora zostaną wyświetlone
jego dzieła.
6. Wyjście z programu. (Jeżeli program nadal się nie
zamyka, należy wcisnąć dowolny przycisk na
klawiaturze.)


Zasady użytkowania:

• Cyfry widniejące przy wyżej wymienionych operacjach są
cyframi, jakie należy odpowiednio wprowadzić i
zatwierdzić klawiszem ENTER. Przykładowo, jeżeli
chcemy wyświetlić wszystkie książki widniejące w
bibliotece, należy po prostu nacisnąć klawisz "1" (bez
cudzysłowu), a następnie wcisnąć klawisz ENTER.

• Program rozróżnia wielkie i małe litery, należy o tym
pamiętać wpisując nazwę autora.

• Program nie obsługuje polskich znaków.

• Program znajdzie autora, jeżeli jego imię i nazwisko
zostanie zapisane w takim formacie: ImieNazwisko (bez
odstępu między imieniem i nazwiskiem, bez polskich
znaków). Na przykład: (AdamMickiewicz). Jeżeli zostanie
wprowadzony odstęp, program nie zadziała poprawnie.

• Jeżeli według programu jednym z autorów książki jest
"X", oznacza to, że program wykrył, iż dana książka ma
mniej niż 3 autorów, a w miejsce autorów
nieistniejących wstawił symbol "X". Nie należy wpisywać
symbolu “X” jako autora podczas wyszukiwania (opcja nr
3), gdyż program poinformuje, że to niedozwolone.


Plik database.txt to format przykładowego pliku pozwalającego na prawidłową pracę programu.
