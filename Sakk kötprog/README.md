# Chess
Programozás 2-re kötelező program

Két játékos sakk. A játékosok felváltva a terminálra beírva adhatják meg, hogy melyik koordinátáról melyik
koordinátára szeretnének lépni.
Ha a lépés szabálytalan a játék ezt jelezze.

1. A programot g++ -o chess.exe chess.cpp paranccsal fordítottam.
2. A programot a ./chess.exe paranccsal fordítottam.

3. 
Sakkbábúk jelölése:
Első karakter kisbetű 'w' vagy 'b' a bábú színe. (white / black)
Második karakter nagybetű a bábú típusa: 
	P -> Pawn, Gyalog
	R -> Rook, Bástya
	N -> kNight, Lovag
	B -> Bishop, Futó
	Q -> Queen, Vezér/Királynő
	K -> King, Király
Például a fehér királynő: "wQ"

A játék kezdetekor egy főmenü kerül elénk. Itt választható a teszt illetve normál opció, vagy az azonnali kilépés.
Ha a két játék opció közül választottunk akkor elindul a játék, ha a kilépést válaszottuk a program kilép. Bármi más inputot újrakér.
A konzolra kirajzolódik elénk a sakktábla, a kezdő pozícióban felállítva. Amelyik színű játékos következik az kap egy utasítást hogy fogjon meg egy bábút.
A várt input két karakter, ahol az első egy kisbetű <a - h> között, a második pedig egy szám <1-8> között. Bármi más input hatására kiírja hogy hibás, és újrakéri.
Ha egy olyan koordinátát adunk inputnak, ahol egy adott színű bábú létezik, akkor azt "megfogjuk".
Ha teszt módban indítottuk a játékot akkor itt kapunk segítséget, hova tud lépni a megfogott bábú.
Ez a segítség azonban nem ellenőrzi, hogy a lépés után sakkban leszünk-e, nem feltétlen legális egy lépés amit itt kiír.
A következő input szintén két karaktert vár, előzőhöz hasonlóképp. [a-h][1-8] Bármi más input hatására kiírja hogy hibás, és újrakéri.
Lehetséges input itt még a "repick". Ha "repick"-et adunk inputnak újra választhatunk bábút, amivel lépni szeretnénk.
Ha a két lépésre vonatkozó input megérkezett, leellenőrzi a program tud-e úgy lépni a bábú, ha tud pedig a lépés után leellenőrzi, hogy sakkban lesz-e a lépés után.
Ha nem tud úgy lépni a bábú arra ír ki üzenetet. "Invalid move."
Ha sakkba kerül a lépés után a játékos pedig "Check!" üzenetet ír ki. Segítség képpen azt is kiírja milyen bábú okozza a sakkot. 
Mindkét esetben a második inputot kéri újra, tehát a bábú már meg van fogva ebben a helyzetben, és újra kéri hova szeretnénk lépni vele.
Itt is használható a "repick" opció.
Ha háromszori próbálkozásra nem találunk olyan lépést ami után nem lennénk sakkban. A játék mattnak veszi.
Ha matt helyzet van, a program kiírja a logot, majd kilép.
Ha sikerült a lépés a logba beírjuk a megtett lépést, majd a kört a másik színű játékos folytatja.
A második körtől kezdve minden kör elején ellenőrizzük sakkban van-e az adott szín, ha igen a "Check!" kiírás jelenik meg.
Itt is kiírja segítség képpen milyen bábútól van sakkba az adott játékos.

Minden input újrakérésnél kirajzolódik a tábla is újra.

Példa input:
Főmenü:
	1 -> A program normál módú indítása.
	2 -> A program teszt módban indítása.
	3 -> A program kilép.
Bábú megfogása:
	"Fehér kör"
	a2 -> Az a2-n levő gyalog megfogása.
	a4 -> Az a2-n levő gyalog a2es mezőről, az a4-es mezőre kerül.

	"Fehér kör"
	a7 -> Az inputot újrakéri, fehér körben nem mozdulhat az a7-es mezőn levő fekete gyalog.
	d1 -> Megfogjuk a d1-es mezőn levő királynőt.
	c6 -> "Invalid move. Where do you want to move?" szöveget írja ki és újrakéri az inputot.
	repick -> A ciklus elejére lép, újrakéri az első inputot, melyik bábút akarjuk megfogni.


	



