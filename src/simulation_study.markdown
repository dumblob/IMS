% Výroba reklam BOSE\
  (Okruh 4: SHO Výrobní linka)
% Jan Pacner (xpacne00@stud.fit.vutbr.cz)
  Lukáš Frencl (xfrenc00@stud.fit.vutbr.cz)
% 2012-12-01 13:09:22 CET

\clearpage

Úvod a motivace
===============

V\ této práci je modelován systém pro poloautomatizovanou výrobu světelných reklam BOSE z\ 2\ cm tlustého plexiskla. Tento systém byl reálně nasazen a úspěšně uspokojil všechny zákazníky. Model se zaměřuje především na zjištění maximální propustnosti použitého řešení výroby a navržení vylepšení pro místa, která se ukázala jako slabiny. Modelovaný systém je unikátní, protože veškerá činnost byla řízena jednotlivými zaměstnanci a nebyly k\ tomu využity automatické výrobní linky. Ačkoliv počet a objem zakázek tyto jednoznačně vyžadoval. Pro účely modelování byly nastudovány způsoby opracování plexiskla (lepení, řezání, broušení), způsoby lakování materiálů s\ hladkým povrchem a obecné zásady pro výrobu světelných reklam.

Přispěvatelé
------------

Modelovaný systém byl reálně nasazen v\ roce 2011 ve firmě Elektro\ Drapač\ s.r.o[^eldr] pod vedením Ing.\ Vodičky, který tento výrobní proces spolu s\ mistrem výroby, panem Jandáčkem, navrhoval. Jan Pacner, spoluautor modelu, se vysokou měrou podílel na realizaci navrženého systému. A\ sice většiny jeho součástí. Model tedy vychází ze vzpomínek na reálný systém a přebírá z\ něho veškeré údaje. Model včetně této studie byl vytvořen v\ rámci školního projektu studenty Lukášem Frenclem a Janem Pacnerem.


[^eldr]: Elektro Drapač. *Elektro Drapač s.r.o* [online]. 2012------, [cit. 2012-12-08]. Dostupné na: <http://www.eldr.cz/>.

Validita modelu
---------------

Experimentováním s\ vytvořeným modelem bylo zjištěno, že celková propustnost navrženého systému výroby je vysoká. Reálně však nikdy tohoto nebylo dosaženo, protože zaměstnanci byli povinni každý den vykonávat práce na různých paralelně zpracovávaných výrobních procesech (tedy ne pouze výroba reklam BOSE). A\ proto žádný zaměstnanec nesetrval v\ modelovaném systému po delší domu než 3\ dny. Výkonnost modelovaného systému se tedy odvíjela od zručnosti právě zapojených zaměstnaců. Tím byla také řízena celková rychlost výroby namísto úplného zastavování procesu výroby reklam BOSE. Toto bylo možné jenom díky vysokému podílu brigádníků mezi zaměstnanci. Zatížení jednotlivých zařízení a výsledná propustnost v\ modelu však zcela zjevně aproximovala modelovaný systém ve chvíli, kdy byli nasazeni nejvýkonnějších zaměstnanci z\ důvodu náhlého přílivu objemných objednávek.

Výroba světelné reklamy BOSE
============================

Světelná reklama je hmotný předmět sloužící k\ výraznému reprezentování jakékoliv entity (ať už hmotného nebo nehmotného charakteru), využívající k\ tomu světla (lidským okem viditelného spektra záření) a znalostí běžných lidí (čtení, vizuální představivost apod.).

Stavba reklamy BOSE
-------------------

V\ případě světelných reklam BOSE se jednalo o\ předmět o\ velikosti 50x25x8\ cm složený ze tří typů dílů. Byli jimi kovová konstrukce, napájecí zdroj a 4\ písmena z\ 2\ cm tlustého plexiskla.

### Kovová konstrukce

Kovová konstrukce byla svařena ze 7\ dílů. Tyto svářečské práce byly však nejméně časově náročné, protože byly zařizovány soukromníkem, který o\ vlastní výrobě nepodával žádné informace. Po přijetí objednávky na reklamy BOSE byl vždy odpovídající počet urgován u\ svářeče a ten do 2\ dnů stihl vždy objednávku uspokojil. Vzhledem k\ níže uvedeným faktům ohledně časové náročnosti dalších úkonů ve výrobě byla tato doba naprosto zanedbatelná a nebyla tedy vůbec modelována.

### Napájecí zdroje

Napájecí zdroje nebyly vyráběny, nýbrž objednávány již jako hotový výrobek a sice velice nepravidelně a v\ různých objemech, protože tyto byly využívány ještě v\ dalších paralelně bežících výrobních procesech nesouvisejících s\ výrobou reklam BOSE. Nebylo tedy možné nalézt přímou souvislost množství těchto zdrojů s\ objednávkami reklam BOSE (ostatní výrobní procesy vyžadovaly řádově větší počty těchto zdrojů) a tedy určit jak zdroje přicházely do modelovaného systému. Protože ve skladu, kde byly tyto zdroje dočasně umístěny, se jich vždy nacházel potřebný počet, nebyly tyto do modelu zahrnuty.

### Písmena z\ plexiskla

Písmena z\ plexiskla tvořila převážnou část výroby, protože zahrnovala velké množství operací. Nejprve musely být připraveny plexisklové desky o\ tloušťce 2\ cm slepením dvou plexisklových desek o\ tloušťce 1\ cm. K\ tomuto kroku bylo přistoupeno po zjištění v\ jiném výrobním procesu, že 2\ cm tlusté desky o\ potřebné velikosti se nikde v\ Evropě nevyrábí. Tento drahý proces zahrnoval zaměstnanecký čas při spojování, vytvrzení, cenu spojovacího materiálu a výrobních prostor.

Ke spojování byla nejprve zkoušena různá lepidla, avšak tato byla dražší a tvořila nechtěné bublinky, které měly velice nežádoucí vliv na odrazivost světla uvnitř výsledné tlusté desky. Proto se přistoupilo k\ využití transparentní zalévací pryskyřice, se kterou se lépe pracovalo (neschnula tak rychle), ale především netvořila bublinky. Přesto byla tato operace lepení náročná natolik, že se desky výráběly v\ předstihu, a protože po celou dobu přicházejících objednávek nebyly tyto nikdy vyčerpány, nebyl ani dostupný počet desek zahrnutý do modelu. Ostatní výrobní procesy též těchto desek využívaly.

Desky byly poté využívány na poloautomatickém elektronickém plotteru, který zajišťoval frézování žlábků a rozřezání na jednotlivá písmena. Plotter obsluhovala osoba, která vždy před každým během plotter vyčistila, zkontrolovala, seřídila, připravila správný nástroj a desku. Tato příprava mu zabrala 25 až 50 minut. Pro desky bylo vytvořeno optimální rozložení písmen tak, aby na desce byl stejný počet každého ze čtyř typů písmen a aby byla deska co nejlépe využita. Bylo zapotřebí zohlednit minimální vzdálosti písmen, aby se nevylamovaly tenké hrany po vyfrézování žlábků. Na desku se takto vešlo 68 písmen. Přesto se často písmeno polámalo a průměrně se jednalo až o\ 20% vyfrézovaných písmen z\ každé desky. Běh plotteru byl tedy konstantní a trval vždy 75 minut. Ostatní výrobní procesy tento plotter nevyužívaly. Vzhledem ke komplikovanosti a ceně výroby desky bylo nutné co nejvíce šetřit, a proto se deska načínala až když se nastřádal potřebný počet objednávek, přičemž důležitější objednávky měly přednost. Důležitost objednávek byla zaznamenána číslem na přepravce a takto bylo možné zpracovat až 4 úrovně důležitosti. Vzhledem k\ vysoké chybovosti se kladlo veliké úsilí na vylepšení a bylo tedy zběžně otestováno rozřezání písmen laserem, který nevykazoval žádnou chybovost. Díky užšímu řezu a zmenšení vzdáleností mezi rozvrženými písmeny na desce se zvýšila výtěžnost jedné desky na 84 písmen. Celý běh zpracování desky se však použitím laseru a většího počtu písmen prodloužil o\ 22 minut, přičemž automatická výměna nástroje pro frézování žlábků za laser trvala stejnou dobu jako výměna řezací hlavice za frézovací. Takto vyřezaná písmena však měla vysoce hladký povrch z\ boku a vyžadovala náročnější zpracování při broušení, což se projevovalo prodlouženou dobou broušení, a to od 10 do 15 minut na jedno písmeno. Tento způsob nebyl uveden do praxe, protože se odhadovalo větší zpoždění při výrobě, ačkoliv by se jednoznačně ušetřilo na opotřebených řezacích hlavicích, které vydržely jenom několik desítek běhů řezání desek.

Takto připravená písmena byla poté nehledě na typ přepravována v\ bedýnkách s\ označením, ke které objednávce daná várka patří, po 8 kusech k\ broušení. A\ to v\ pořadí určeném důležitostí objednávky. Brusič měl za úkol písmena obrousit z\ vnějších stran a stran ve vnitřních otvorech tak, aby na plexisklu držel lak (byla přesně stanovená hrubost povrchu pro vybraný způsob lakování). Nejprve byly vyzkoušeny různé varianty lakovacích prostředků, které měly držet i\ na lesklých materiálech, avšak tyto se neosvědčily. Možnost naleptat materiál chemickými látkami nepřipadala v\ úvahu, protože výsledkem nebyl zdrsněný povrch s\ mikroskopickými špónami, nýbrž velice jemné mikroskopické vlnky. Přistoupilo se tedy k\ ručnímu broušení pomocí smirkových papírů namotaných na KömaTexových[^komatex] tyčkách. Toto však bylo nesmírně pracné a neproduktivní. Výrazné zrychlení a zárověň zvýšení kvality poskytlo použití plochých elektrických brusek na vnější plochy. Vnitřní otvory však musely být nadále broušené ručně. Nejlepším řešením se však ukázala tvorba vlastního brousícího nástroje jako univerzální nástavec na vrtačku, se kterým bylo možné obrousit jak vnější hrany, tak ty vnitřní. Tento brousící nástroj se však přibližně po 50 až 80 obroušených písmenech zničil a musel být vyroben znovu. Výroba trvala 20 až 30 minut. Písmena byla broušena podle priority, která byla uvedená na přepravce. Po obroušení písmena, které trvalo 9 až 13 minut (včetně ofoukání pomocí vzduchového čerpadla), byla tato opět vložena do příslušné krabice a přepravena k\ lakování.

[^komatex]: Profine GmbH. *KömaTex* [online]. 2009------, [cit. 2012-12-08]. Dostupné na: <http://www.kommerling.cz/komatex.html>.

Lakování sestávalo z\ přilepení jednotlivých písmen oboustranně lepící pěnovou páskou na čtyřhranné jekly (podle důležitosti objednávky na přepravce byly nalepovány nejprve ty s\ vyšším číslem). Na každou tyč se vešlo maximálně 12 písmen. Jekly byly poté zaneseny do lakovny, kam se vešly pouze 4. A\ následně nalakovány jednou vrstvou laku, což trvalo 55 až 85 minut v\ závislosti na šikovnosti lakýrníka a množství aktuálně namíchané barvy. Čerstvě nalakovaná písmena na tyčích byla vynesena do odkládacích prostor na zaschnutí a byla započata příprava dalšího lakovacího běhu lepením obroušených písmen na jekly. Každé písmeno muselo být nalakováno právě devětkrát, přičemž první 2 vrstvy byly čistě bílou barvou, aby co nejlépe odrážely světlo emitované LED diodami, další 3 vrstvy šedou barvou plnící funkci neutrálního oddělovače, dále 2 vrstvy tmavší podkladovou barvou a nakonec 2 vrstvy vnější finální barvou. Další vrstva se vždy mohla nanést až po částečném zaschnutí, které trvalo přibližně 60 minut. Po nanesení všech 9 vrstev bylo nutné nechat barvu 24 hodin zaschnout a až poté mohla být písmena sundána. Čtyřhranných jeklů určených pro lakovací účely bylo několik desítek (odhadem 35), tedy vysoký přebytek. Ze dvou lakovacích běhů se muselo často jedno až dvě písmena přelakovat, protože obsahovala alespoň jednu bublinku v\ laku (nezávisle na typu vrstvy), což se projevovalo jako malé průsvitné dírky.

Nakonec byla písmena slepena z\ tyčí, rozdělena zpět do příslušných přepravek a přemístěna na stoly, kde probíhala kompletace reklamy. Tato se skládala z\ vložení LED diodových pásků do žlábků vytvořených plotterem v\ jednotlivých písmenách. Připájení těchto pásků ke zdroji (včetně provléknutí kabelů otvory v\ železné konstrukci, navlečení průchodek a natavení smršťovacích bužírek). Zalepení pásků v\ písmenku lepící fólií, přišroubování písmenek na železnou konstrukci a finální očištění od nečistot spolu se zabalením do kartónové krabice. Tuto kompletaci prováděli většinou 2 zaměstnanci -- brigádníci. Zkompletovat jednu reklamu trvalo v\ závislosti na zručnosti brigádníka 55 až 70 minut. Takto zabalené reklamy byly připravené na vyzvednutí přepravní službou a odvezení k\ zákazníkovi.

Jak vypadá reklama po nasazení si lze prohlédnout na fotografii \ref{bosepic}.

![Reklama BOSE na výstavě High\ End\ Praha 19.2.2011 \label{bosepic}](bose_prague00.jpg)

### Objednávky

Tato informace byla firmou zatajena a proto jsou údaje pouze odpozorované z\ běžného provozu. Předpokládá se příchod větších objednávek (např. 60 kusů reklam) a to přibližně jednou za dva pracovní dny. Některé objednávky byly důležitější, ale mnoho objednávek nemělo nijak zvýšenou prioritu[^prior]. Běžné objednávky byly označeny nulou a nejprioritnější trojkou.

[^prior]: Peringer, Petr. *Prezentace k\ předmětu IMS*. 2012, str. 181.

Postup tvorby modelu
--------------------

Byla zvolena diskrétní simulace[^discsim] vzhledem k\ charakteru problému, který odpovídá zřetězení jednotlivých úkonů (akcí), aniž by se tyto mezi sebou ovlivňovaly jinak, nežli skrze časové zpoždění. Každá akce je v\ našem případě definována pouze vstupem, výstupem a časem, po který byla prováděna. Výpadky při provádění akcí jsou řešeny v\ každé akci interně. Mezi dvěmi po sobě jdoucími akcemi se může, avšak nemusí objevit prodleva, kterou lze též popsat dobou trvání. Všechny tyto doby trvání mohou být dynamicky závislé buď na aktuálním stavu systému nebo na empiricky zjištěné pravděpodobnosti výskytu jistých hodnot, popřípadě na obojím. Pro simulaci by nebyly vhodné metody spojité simulace[^spojsim], které by v\ případě modelování výroby reklam byly vysoce náročné na implementaci. A\ vzhledem k\ zadání, které neposkytuje detaily, ve kterých by bylo vhodné využít spojité simulace, by neměly žádnou přidanou hodnotu (poskytovaly by obdobnou, ne-li horší, přesnost). Využití kombinované simulace[^kombsim] postrádá smysl ze stejných důvodů.

[^discsim]: Peringer, Petr. *Prezentace k\ předmětu IMS*. 2012, str. 122.
[^spojsim]: Peringer, Petr. *Prezentace k\ předmětu IMS*. 2012, str. 211.
[^kombsim]: Peringer, Petr. *Prezentace k\ předmětu IMS*. 2012, str. 270.

Použité technologie a metody
----------------------------

Použité metody využívají ověřených postupů modelování systémů hromadné obsluhy[^sho]. K\ naplnění těchto principů je využita simulační knihovna SIMLIB[^libsimlib] nabízející objektovou abstrakci[^objektabstr] jednotlivých operací[^operace] a procesů[^procesy], využívajících tyto operace. SIMLIB implementuje kompletní simulační prostředí pro diskrétní simulaci, a proto nebyly použité žádné další prostředky. Dostupné prostředky z\ knihovny byly však pro potřeby simulace rozšířeny o\ možnost dávkového zpracování požadavků procesů. Jednotlivé procesy tedy namísto žádosti o\ provedení akce (zabrání zařízení) žádají jiný proces (agenta), který to udělá za ně, avšak až poté, co se nashromáždí dostatečný počet požadavků.

[^sho]: Peringer, Petr. *Prezentace k\ předmětu IMS*. 2012, str. 139.
[^libsimlib]: Peringer, Petr. *SIMLIB Home Page* [online]. 2011-10-31, [cit. 2012-12-08]. Dostupné na: <http://www.fit.vutbr.cz/~peringer/SIMLIB/>.
[^objektabstr]: Peringer, Petr. *Prezentace k\ předmětu IMS*. 2012, str. 171.
[^operace]: Peringer, Petr. *Prezentace k\ předmětu IMS*. 2012, str. 183, 187.
[^procesy]: Peringer, Petr. *Prezentace k\ předmětu IMS*. 2012, str. 174.

Modelový čas je spřažen s\ reálnou denní a týdenní pracovní dobou, čímž je umožněno simulovat dlouhodobou výrobu (měsíce, roky). Je to též nutné pro správné vystižení faktu, že barva po nalakování musí schnout 24\ hodin.

Koncepce
========

Model modeluje pracovní týden libovolněkrát za sebou. Předpokládá příchod objednávek na jisté množství reklam BOSE pouze v\ pracovní době a sice exponenciálně se střední hodnotou jednoukrát za dva pracovní dny. Objednávky jsou přijímány od různých zákazníků v\ různých počtech s\ minimálním počtem kusů jedna.

Konceptuální model
------------------

Byly přijaty následující abstrakce a zjednodušení. Objednávka je ihned po příchodu do systému rozdělena na nejmenší jednotky, se kterými model pracuje. Tyto představují přepravky s\ vlastní prioritou a prochází výrobním procesem zcela individuálně. Každá akce (operace) prováděná ve výrobním procesu tedy přijímá a emituje právě tyto přepravky s\ tím, že zohledňuje prioritu přiřazenou každé přepravce. Každá z\ těchto přepravek obsahuje právě takový počet písmen, aby z\ ní bylo možné sestavit několik celých reklam. V\ modelu je tato kapacita nastavena na dvě reklamy (tedy osm písmen) přesně podle reálného systému. Přestože objednávky nemusí odpovídat celému násobku kapacity přepravky, je tento problém zanedbán a v\ takových případech se vyrobí několik reklam navíc. V\ modelu to činí právě jednu reklamu s\ pravděpodobností příchodu takové objednávky $\frac{1}{2}$ (sudá a lichá čísla jsou v\ exponenciálním rozložení se střední hodnotou 0.5 rovnoměrně zastoupena).

Tyto přepravky putují nejprve do plotteru, který je spuštěn vždy až po nashromáždění dostatečného počtu žádostí o\ písmenka. Zde nastává obdobná situace jako při dělení objednávky do přepravek -- deska není zcela využita (rozřezána) v\ případě, že počet písmenek z\ desky nebude celým násobkem počtu písmenek v\ přepravce. Po osobní konzultaci s\ obsluhou plotteru vyšlo najevo, že jsou písmenka rozvržena na desce tak, aby písmena byla dál od sebe a snížilo se riziko poškození písmen polámáním. Teprve poté se dosahovalo zmíněné 20% ztrátovosti. V\ modelu je tedy tento problém též zanedbán a vybírá se nejbližší menší násobek objemu přepravky (v\ případě rovnosti k\ tomuto problému nedochází). Malé objednávky tedy musí čekat až se naakumuluje dostatečné množství objednávek, jinak nejsou zpracovávány. Dále se v\ modelu předpokládá, že výrobního materiálu (lepených plexisklových desek) je vždy dostatek. S\ 20% pravděpodobností jsou písmena zničena (nerozlišuje se typ jednotlivých písmen, protože v\ reálném systému nebyly zaznamenány žádné známky různé chybovosti u\ různých písmen). Tato je nutné vyřezat z\ desky v\ další várce (avšak nyní s\ vysokou prioritou).

Vyřezaná písmena jsou seskupena do přepravek a podle priority seřazena u\ brusiče. Tomu se po 50 až 80 obroušených písmenech zničí nástroj a musí si ho 20 až 30 minut vyrábět. Mezitím je broušení pozastaveno.

Obroušená písmena jsou znovu zařazena do odpovídajících přepravek a předána lakýrníkovi. Ten je nalepí na jekly a ihned lakuje. Počet jeklů byl zanedbán vzhledem k\ empirickému pozorování reálného systému při výrobě, kdy nikdy nebyl zaznamenán jejich nedostatek, ani tomu nic nenasvědčovalo. Celková doba strávená v\ lakovně zahrnuje i\ dobu lepení písmen na jekly, dobu odlepování z\ jeklů, dobu výměny tyčí mezi lakovnou a odstavným místem a samotné lakování. Ve\ 2 lakovacích bězích se nachází až 2 špatně nalakovaná písmena. Protože model pracuje s\ přepravkou jako nejmenší možnou jednotkou, je tato chybovost modelována nad každou přepravkou (je tedy vždy přelakována celá přepravka) v\ každém běhu s\ pravděpodobností
\begin{equation}
\frac{ \frac{ uniform(0,2) }{ 2 } }{ \text{počet přepravek v 1 lakovacím běhu} }
\ . \label{paintshopfailureformula}
\end{equation}

Takto vybrané chybné přepravky jsou poté lakovány znovu s\ vysokou prioritou hned v\ následujícím běhu.

Po úspěšném nalakování jsou přepravky s\ 24\ hodin zaschlými, právě z\ jeklů odlepenými, písmeny doneseny ke kompletačním stolům a zde podle priority postaveny celé reklamy BOSE. Kabely na prodrátování, cín, průchodky, smršťovačky, šrouby apod. nejsou zohledňeny, protože jich byl vždy plný sklad. Jakmile jsou takto zpracovány všechny přepravky z\ dané objednávky, je objednávka považována za vyřešenou a opouští model.

Skutečnost, že běžící plotter a lakující lakýrník nemohou na konci směny přerušit právě rozpracovanou činnost model nezohledňuje, protože tyto případy byly v\ reálu řešeny protažením pracovní doby danému zaměstnanci spolu s\ povolením pozdního příchodu následující pracovní den, čímž se vyrovnaly časové rozdíly. Celý model je znázorněn na obrázku \ref{seqdiag}.

Znázornění modelu
-----------------

![Znázornění konceptuálního modelu \label{seqdiag}](sequence_diagram02.png)

Architektura a implementace modelu
==================================

Z\ knihovny SIMLIB jsou využity následující bloky, představující jednotlivé části modelu. Modelový čas představuje minuty reálného světa.

Event[^eventclass]
------------------

Tato abstraktní třída je využita pro generování objednávek. Generátor (třída *Generator*) zajišťuje náhodné vygenerování priority a množství reklam, kterými bude nová objednávka určená. Nakonec plánuje příchod další objednávky. Objednávky nejsou generovány mimo pracovní dobu.

[^eventclass]: Peringer, Petr. *SIMLIB Event* [online]. 2011-10-31, [cit. 2012-12-08]. Dostupné na: <http://www.fit.vutbr.cz/~peringer/SIMLIB/doc/html/classsimlib3_1_1Event.html>.

Process[^processclass]
----------------------

Procesy modelují objednávky, přepravky, čas, speciální proces GrinderFailure a zástupné agenty „Batch“ pro dávkové zpracování požadavků jiných procesů.

Proces objednávka (třída *Order*) zajišťuje rozdělení objednávky na podprocesy „přepravka“. Vytvoří tedy nejbližší vyšší počet objektů třídy *Crate* dělitelný kapacitou jedné přepravky. Pak již pouze čeká, až všechny tyto přepravky jsou obsloužené a nakonec vypíše statistiku ohledně doby obsluhy celé objednávky.

Proces přepravka (třída *Crate*) modeluje životní cyklus přepravky tak, jak prochází výrobním procesem. Nejprve se zařadí k\ zájemcům o\ plotter kontaktováním agenta *PlotterBatch*. Jakmile agent oznámí, že je přepravka naplněná vyřezanými písmeny, pokračuje dál a zabírá si brusiče *Grinder*, načež si nechá obrousit všechna jednotlivá písmena v přepravce (každé písmeno se brousí různou dobu). Dále devětkrát požádá agenta *PaintshopBatch* o\ přístup do lakovny s\ čekací dobou schnutí 60 minut. Poté se písmena nechají schnout zbylých 23 hodin. Přepravka je poté přiřazena k\ jednomu z\ dostupných kompletačních stanovišť a po uplynutí doby potřebné pro kompletaci se informuje objednávka (rodič), že tato přepravka byla právě úspěšně obsloužena.

Procesy Batch (třídy *PlotterBatchC* a *PaintshopBatchC*) modelují agenty pro procesy *přepravka*, kteří shromažďují požadavky od více procesů *přepravka* a po dosažení minimálního počtu zaberou zařízení *Plotter* nebo *Paintshop* a po skončení obsluhy žádající procesy *přepravka* probudí, aby tyto mohly pokračovat v\ běhu. V\ implementaci je využita prioritní fronta *Queue*[^queueclass] nacházející se v\ knihovně SIMLIB. Chybovost lakýrníka je počítán s\ pravděpodobností uvedenou ve vztahu \ref{paintshopfailureformula} a chybovost plotteru jako pravděpodobnost, že právě daná přepravka je celá špatně vyřezaná (není zohledněna nepřesnost vzniklá v\ případě, že počet vyřezaných písmen z\ jedné desky není celočíselný násobek počtu písmen v\ jedné přepravce). Vybrané chybné přepravky se v\ obou případech (*PlotterBatch* a *PaintshopBatch*) zařadí na začátek prioritní fronty pro následující běh. Protože je využívána pravděpodobnost při výběru chybných přepravek, nemělo by docházet k\ vyhladovění, kdy by byla vybírána tatáž přepravka neustále dokola.

Čas (třída *WorkingHoursC*) je v\ modelu modelován jako samostatný proces, zabírající všechna zařízení a informující agenty a generátor objednávek v\ určitých intervalech na určitý čas (pracovní volno) tak, aby bylo možné přesně zohlednit pracovní dobu, která má vliv např. na zmíněné úplné zaschnutí barvy. Takto je modelováno 5 pracovních dní v\ týdnu spolu s\ 8-hodinovou pracovní dobou. Po uplynutí pracovního volna jsou zařízení, agenti a generátor znovu informováni, že mohou pokračovat v\ rozpracované činnosti. Agenta *PaintshopBatch* bylo nutné informovat o\ pozastavení činnosti proto, že sám se dostával do stavu provádění činnosti pouze vlastním zabráním zařízení *Paintshop*, avšak při náhlém zabrání tohoto zařízení procesem *čas* mohlo dojít k\ uvolnění tohoto zařízení procesem *PaintshopBatch* namísto procesu *čas*. Toto chování není zcela zřejmé a vychází ze skutečnosti, že priorita obsluhy je v\ knihovně SIMLIB řešena pomocí pasivace právě obsluhovaného procesu v\ daném zařízení. Vzhledem k\ tomu, že žádosti od procesů *přepravka* mohly proces *PaintshopBatch* kdykoliv probudit, musela být zavedeno výše uvedené informování. Agenta *PlotterBatch* však nebylo nutné informovat o\ pozastavení činnosti, protože nové požadavky (aktivace procesu *PlotterBatch*) nepřicházely díky uspanému generátoru objednávek. Časovou jednotkou je minuta.

Speciální proces GrinderFailure slouží jako pomůcka pro modelování výpadku brusiče v\ případě, že se mu rozbil brousící nástroj. Protože doba, po které se nástroj rozbíjí je přímo závislá na počtu obroušených písmen, řídí si tento okamžik zařízení Grinder samotné. Po dokročení na danou, náhodně vygenerovanou mez počtu obroušených písmenek je zavolán právě tento proces, který zpětně s\ vysokou prioritou obsluhy zařízení zabere po dobu výroby nástroje a pak se zase pasivuje.

[^processclass]: Peringer, Petr. *SIMLIB Process* [online]. 2011-10-31, [cit. 2012-12-08]. Dostupné na: <http://www.fit.vutbr.cz/~peringer/SIMLIB/doc/html/classsimlib3_1_1Process.html>.
[^queueclass]: Peringer, Petr. *SIMLIB Queue* [online]. 2011-10-31, [cit. 2012-12-08]. Dostupné na: <http://www.fit.vutbr.cz/~peringer/SIMLIB/doc/html/classsimlib3_1_1Queue.html>.

Facility[^facilityclass]
------------------------

Komponenta zařízení představuje v\ modelu prováděné operace nad přepravkami. Tedy plotter (*Plotter*), brusič (*Grinder*), lakýrník (*Paintshop*) a jednotlivé kompletační stoly (*Desks*) jsou zařízeními. Plotter a lakýrníka si však *přepravka* nemůže zabrat jenom pro sebe, protože tato dvě zařízení pracují v\ dávkovém módu, a proto bylo vytvořeno již zmíněné rozšíření, kdy tato zařízení jsou zabírána zástupným procesem (agentem), který tvoří prostředníka.

[^facilityclass]: Peringer, Petr. *SIMLIB Facility* [online]. 2011-10-31, [cit. 2012-12-08]. Dostupné na: <http://www.fit.vutbr.cz/~peringer/SIMLIB/doc/html/classsimlib3_1_1Facility.html>.

Histogram[^histogramclass]
--------------------------

Sběr dat pro vyhodnocní simulace je prováděn zaznamenáváním potřebných měření v\ průběhu simulace do několika histogramů. Po ukončení simulace jsou naměřené výsledky souhrnně vyhodnoceny a uloženy.

[^histogramclass]: Peringer, Petr. *SIMLIB Histogram* [online]. 2011-10-31, [cit. 2012-12-08]. Dostupné na: <http://www.fit.vutbr.cz/~peringer/SIMLIB/doc/html/classsimlib3_1_1Facility.html>.


Simulační experimenty
=====================

Cílem experimentování s\ vytvořeným modelem je nalézt slabiny modelovaného systému (pokud takové existují) a navrhnout možná řešení včetne simulace těchto nových přístupů. Základním kritériem výběru vhodnosti daného řešení je celkový čas, po který jsou objednávky zpracovávány. Dalším důležitým faktorem je čas strávený v\ jednotlivých zařízeních, a\ tedy podíl dané operace na celkovém času zpracování objednávek, z\ čehož lze odvodit, která operace zdržuje výrobní proces nejvíce.

Postup experimentování
----------------------

Simulace je spuštěna dvanáctkrát za sebou. Pokaždé s\ rozdílným celkovým časem simulace, kdy tento čas je dán posloupností 3,\ 6,\ 9,\ ...,\ 36 měsíců. V\ grafech jsou poté vyneseny statistiky z\ posledního nebo průměr ze všech běhů. Se stejnými vstupními podmínkami jsou spuštěny všechny experimenty s\ tím rozdílem, že je proveden podmíněný překlad a mění se některé části modelu. Výsledky jsou nakonec vyhodnoceny, vyneseny do grafu a uvedeny níže u\ příslušného experimentu.

Experiment 1
------------

Cílem tohoto experimentu bylo ověření validity modelu a zjištění úzkých hrdel v\ propustnosti celého systému. Grafy na obrázku \ref{exp1pic} popisují jednotlivé naměřené hodnoty.

Z\ prvního grafu, který zobrazuje stav po 3 letech nepřetržité výroby, lze odvodit, že počet objednaných reklam nemá vliv na délku zpracování objednávky. Ostré změny lze přisuzovat náhodnému příchodu objednávek spolu s\ neočekávanou (náhodnou) prioritou. Střední hodnota po těchto 3 letech výroby se pohybuje okolo 527062 minut, což je přibližně jeden pracovní rok a dva pracovní dny.

Druhý graf znázorňuje zcela zřejmý trend, že se nestíhají zakázky uspokojovat a že výroba není ani zdaleka stavěná na takto rychlý přísun objednávek.

Poslední graf dává najevo, že bezesporným úzkým hrdlem je lakování a broušení. A\ naopak lze vyčíst, že je naprosto zbytečné nasazovat dva zaměstnance na kompletaci.

![Ilustrace chování simulačního modelu 1\label{exp1pic}](exp1.png)

Experiment 2
------------

Cílem tohoto experimentu bylo zjištění, jaký vliv bude mít změna vyřezávání písmen z\ plexisklové desky. Namísto řezací hlavice byla tedy modelována laserová hlavice a vše co z\ toho plyne. Tedy zpoždění celého procesu vyřezávání, zpoždění procesu broušení laserem vyřezaných písmen apod.

První dva grafy na obrázku \ref{exp2pic} zjevně odpovídají výsledkům z\ prvního experimentu, což je očekávané chování.

Naměřené výsledky ve třetím grafu na obrázku \ref{exp2pic} však zcela zjevně potvrzují, že vliv použití laseru je spíše margiální záležitost a/nebo dokonce i\ mírně kontraproduktivní, protože přenáší ještě větší zátež na brusiče.

![Ilustrace chování simulačního modelu 2\label{exp2pic}](exp2.png)


Výsledky experimentování
------------------------

Výše uvedené experimenty byly spuštěny vícekrát pro potvrzení validity a pokaždé výsledky vypadaly obdobně jako je uvedeno výše. Při experimentování se podařilo nalézt chybu v\ práci s\ histogramy v\ souvislosti s\ náhodným přepínáním kontextu, kdy byly do histogramů ukládány hodnoty různě v\ různých časech a ihned po ukončení simulace tedy došlo k\ tomu, že bylo mnoho rozpracovaných procesů *přepravka* a data z\ těchto procesů v\ histogramech chyběla, což významnou měrou ovlivňovalo výsledky.

Experimenty potvrdily, že systém má úzké hrdlo na místech lakování a broušení písmen. Po 3 letech výroby by situace byla zjevně naprosto neúnosná. Naštěstí byl tento systém aplikován po mnohem kratší dobu (cca 9 měsíců) a zřejmě s\ mírně odlišným rozložením vstupních objednávek jak v\ čase, tak co se množství týče. Pokud by tento systém měl být znovu nasazen, bylo by doporučeno posílit pozice brusiče a lakýrníka a případně oslabit pozice pro kompletaci.

Experimentálně bylo také ověřeno, že rozhodnutí nevyužít laserového řezání bylo nakonec správné, protože celková průměrná doba zpracování objednávky by nebyla kratší, nýbrž spíše delší. A\ co se vytížení týče, tak se ještě o\ trochu zvýšilo vytížení brusiče a snížino průmerné zatížení plotteru.

Další experimentování by dávalo smysl pouze pro vhodnější rozložení vstupních objednávek. V\ opačném případě se systém chová poměrně stabilně a podává stejné výsledky.

Závěr
=====

Experimentálně bylo zjištěno, že modelovaný systém je nedostatečně výkonný, avšak použitelný pro krátké nasazení. Na základě výsledků experimentů s\ pozměněnými metodami výroby (konkrétně využití laserového řezání plexisklových desek) je doporučeno zůstat u\ oddělování písmen řezací hlavicí a neprovádět modernizaci za účelem řezání pomocí laserového nástavce. Je též nutné podotknout, že finanční úspory spojené s\ laserovou hlavicí (oproti často se ničící řezací hlavici) zcela jistě nevykompenzují časovou ztrátu způsobenou zatížením brusiče, a to i\ přesto, že tato není příliš veliká.

Literatura a reference
======================

*   Peringer, Petr. *SIMLIB Home Page* [online]. 2011-10-31, [cit. 2012-12-08]. Dostupné na: <http://www.fit.vutbr.cz/~peringer/SIMLIB/>.

*   Peringer, Petr. *Prezentace k\ předmětu IMS*. 2012, str. 171.

*   Profine GmbH. *KömaTex* [online]. 2009------, [cit. 2012-12-08]. Dostupné na: <http://www.kommerling.cz/komatex.html>.

*   Elektro Drapač. *Elektro Drapač s.r.o* [online]. 2012------, [cit. 2012-12-08]. Dostupné na: <http://www.eldr.cz/>.
