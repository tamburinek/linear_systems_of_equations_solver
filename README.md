# PJC Semestrální práce

Arťom Ňorba 

## Téma - Řešení soustav lineárních rovnic

Semestrální projekt (dále jen "aplikace") má za úkol nálezt řešení zadané soustavy lineárních rovnic. Aplikace nejprve načte rovnice. Učiní tak ze souboru nebo od uživatele (viz. přepínače) a následně vytvoří rozšířenou matici a vypíše soustavu rovnic v jejím správném tvaru (s proměnnými a znamánky). Před tím než aplikace začně algoritmus zvaný GEM, tak si přeskupí rovnice do vhodného pořadí (prohazování řádků je povolenou úpravou při řešení soustav) a následně začne rozšířenou matici upravovat do tvaru horního trojúhelníku, kdy pod hlavní diagonálou jsou samé nuly. Následně aplikace znovu vytiskne soustavu rovnic, ale nyní už ve tvaru po GEMu. Pak se spočítají jednotlivé proměnné a vypíšou se uživateli. Tím program skončí.

## Spuštění aplikace
Aplikace se stáhne z tohoto Gitu a nejlepší možností je otebřít Clion a spustit aplikaci tam. Aplikaci se můžou, ale nemusí předat argumenty. 

## Přepínače
Aplikace nepotřebuje ke spuštění žádný další vstupy. Pokud aplikace nedostane žádný argument, tak běží v "Take Data From User" módu, kdy aplikace čeká na vstupy z klávesnice. Pokud však aplikace dostane argument, tak může nastat několik možností. Přepínat mezi argumenty může uživatel při použití Clion při rozkliknutí Edit Configurations... Nebo pokud je uživatel znalejší, tak může argumenty posílat z terminálu. <br><br>

### 1) --help
Aplikace dostane argument (přepínač) --help a vypíše návod na použití
```
This app solves system of linear equations 
It solves it only in one thread 
But that does not mean that it is useless :/ 
---------------------------
Commands: 
You found this, so you know command --help 
But you can also use command --file which sets app to read from file mode
After that you just have to write file name. 
If you start app without any command - app will be in Take Data From User status
If you start app with unknown command it will stop without result
That is all for commands. 
---------------------------
So this is how app works: 
It takes data from user or file 
After that it prints the matrix in equation shape 
Then it makes some magic (it makes GEM) 
After GEM it prints Matrix in equation shape again 
Then it just prints the results 

Process finished with exit code 0
```
### 2) --file
Aplikace již nebude požadovat rovnice od uživatele, ale bude čekat na název souboru který má otevřít a z něj rovnice načíst. <br>
Při zadávání je potřeba zadat i koncovku .txt !!!
```
Write name of your file: 
three.txt

I started reading numbers from file
Number of variables is 3
I ended reading numbers from file

//code outputs
```

### 3) (neexistující command)
Aplikace nepovoluje neznámé argumenty a hned ukončí běh.
```
I dont know this command - we are finished here

Process finished with exit code 0
```

### 4) (bez argumentu)
Aplikace čeká na počet proměnných a rovnice ke spočítání.
```
Enter how many variables u have for me: 
2

Enter the numbers you want to count: 
2 3 4
5 6 7

//code outputs
```
## Testovací data
Pokud se aplikaci pošle příkaz --file a aplikace žádá název souboru, nalezne ho pouze ve složce textFiles. Pro otestování aplikace je připravena spousta souborů. Nachází se tam soustavy velikosti 3-10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 200 a boss je 1000. Dále se tam nachází soustavy, které nemají řešení (noResult.txt) nebo nekonečně mnoho řešení (infinityResult.txt). Při zadávání je potřeba zadávat i koncovku .txt!!! Při vytváření nových dat je potřeba na první pozici zadat počet rovnic a pak zadat rovnice.

## Výstupy
Výstupem správně spuštěné aplikace může být buď jedno řešení, kdy se pro každou proměnnou vypíše její hodnota. Může se ale stát, že soustava řešení nemá. Pak se vypíše příslušná hláška oznamující užiavteli absenci řešení. Poslední možností je, že soustava má nekonečně mnoho řešení, což se uživateli rovněž oznámí a nalezne jedno řešení soustavy - aplikace bohužel nenalezne jádro. Součástí výstupu do terminálu jsou taky průběžné výpočty (matice po GEMu) a přepis z matice do soustavy rovnic (připíšou se neznámé).

## Implementace
Aplikace běží pouze jednovláknově, ale i přesto dokáže rychle počítat soustavy o 100 - 1000 neznámých. Při větších počtech už je čas počítání opravdu velký.

## Přenositelnost
Aplikace byla napsána v prostředí Clion na počítači běžícím na operačním systému MacOS. Pro splnění požadavku na přenositelnost byla následně aplikace přesunuta a spuštěna na jiném počítači využívající operační systém Windows. Aplikace je tedy bez problému přenositelná a není vázaná na specifický prostředí.

## Měření
Měření proběhlo na operačním systému MacOS, na 4 jádrovém Intel Core i5 taktovaném na 1,4 GHz.<br>
Počítání matic:<br>

3 až 30 rovnic < 8ms.<br>
40 až 60 rovnic < 25ms <br>
70 rovnic - 31ms <br>
80 rovnic - 47ms <br>
90 rovnic - 57ms <br>
100 rovnic - 72ms.<br>
200 rovnic - 481ms.<br>
1000 rovnic - 37515ms <br>




