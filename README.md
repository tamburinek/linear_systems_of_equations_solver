# PJC Semestrální práce

Arťom Ňorba 

## Téma - Řešení soustav lineárních rovnic

Semestrální projekt (dále jen "aplikace") má za úkol nálezt řešení zadané soustavy lineárních rovnic. Aplikace nejprve načte rovnice. Učiní tak ze souboru nebo od uživatele (viz. přepínače) a následně vytvoří rozšířenou matici a vypíše soustavu rovnic v jejím správném tvaru (s proměnnými a znamánky). Před tím než aplikace začně algoritmus zvaný GEM, tak si přeskupí rovnice do vhodného pořadí (prohazování řádků je povolenou úpravou při řešení soustav) a následně začne rozšířenou matici upravovat do tvaru horního trojúhelníku, kdy pod hlavní diagonálou jsou samé nuly. Následně aplikace znovu vytiskne soustavu rovnic, ale nyní už ve tvaru po GEMu. Pak se spočítají jednotlivé proměnné a vypíšou se uživateli. Tím program skončí.

## Spuštění programu

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
Aplikace již nebude požadovat rovnice od uživatele, ale bdue čekat na název souboru který má otevřít a z něj rovnice načíst.
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
## Výstupy
Výstupem správně spuštěné aplikace může být buď jedno řešení, kdy se pro každou proměnnou vypíše její hodnota. Může se ale stát, že soustava řešení nemá. Pak se vypíše příslušná hláška oznamující užiavteli absenci řešení. Poslední možností je, že soustava má nekonečně mnoho řešení, což se uživateli rovněž oznámí.

## Implementace

## Přenositelnost
Aplikace byla napsána v prostředí Clion na počítači běžícím na operačním systému MacOS. Pro splnění požadavku na přenositelnost byla následně aplikace přesunuta a spuštěna na jiném počítači využívající operační systém Windows. Aplikace je tedy bez problému přenositelná a není vázaná na specifický prostředí.

## Měření
Měření proběhlo na operačním systému MacOS, na 4 jádrovém Intel Core i5 taktovaném na 1,4 GHz 




