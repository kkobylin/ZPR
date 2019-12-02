# Chess


### Instalacja:
1.  ```chmod +x script_1_71_0.sh```
2. Instalowanie wszystkich potrzebnych narzędzi do kompilacji Boost python
```./script_1_71_0.sh```
3. Wejść w katalog chess_engine i wykonać komendy:

### Krótki opis
   Na daną chwilę stworzone są wszystkie 3 moduły aplikacji w wersji podstawowej(klient w JavaScript, serwer w Pythonie oraz logika w C++) oraz komunikacja pomiędzy nimi. Klient pobiera skąd oraz dokąd dana figura ma być przemieszczona i wysyła te informacje za pomocą REST do serwera. Następnie serwer wykorzystując Boost::Python i dynamiczną bibliotekę z plikami cpp sprawdza poprawność danego ruchu i odsyła tę informację do klienta. 
    Zbudowanie biblioteki Boost::Python zajęło nam do tej pory zdecydowanie najwięcej czasu z powodu wielu napotkanych tam problemów i głównie przez to aplikacja w tym momencie działa poprawnie jedynie na Linuxie, a kod wymaga refactoringu. Co do logiki programu dla przykładu, poprawnie działają pierwsze ruchy pionków.
    Do zbudowania aplikacji wykorzystywane są skrypty Shella oraz Cmake. Przykładowy test jednostkowy znajduje się w katalogu chess_engine/test.













