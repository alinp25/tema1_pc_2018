Nume: Pisica Alin-Georgian
Grupa: 314CC

Timp aproximativ de lucru: 3 ore.
Memory leaks in Valgrind: 0.

Cerinta 1 (codarea textului):
Codificarile fiecarei litere sunt pastrate intr-un array de siruri de caractere,
de  lungime  26,  cate una pentru fiecare litera a alfabetului, permitand astfel
accesarea  usoara  a  elementelor  si  a  textului reprezentativ pentru aceasta.
Ulterior,  sirul  transmis  ca  input este parcurs element cu element, urmand ca
fiecare litera sa fie adaugata la sirul codat.  Complexitatea rezolvarii este de
O(N), unde N reprezinta lungimea sirului ce urmeaza a fi codificat.

Cerinta 2 (decodificarea textului):
Asemanator cerintei 1, intr-un array sunt pastrate codificarile fiecarei litere.
Este parcurs sirul codificat, caracter cu caracter, acesta fiind adaugat intr-un
cod curent. In cazul in care caracterul intalnit difera de ultimul caracter  din
codul curent, cautam  litera  corespunzatoare  acestuia  in  array-ul  mentionat
anterior, adaugand-o in sirul decodificat. La intalnirea cifrei 1 vom pastra  un
flag (isUpperCase) ce va retine daca urmatoarea litera adaugata va fi  o  litera
mare. Complexitatea rezolvarii cerintei este O(26 * N), unde N este  numarul  de
cuvinte rezultate in urma decodificarii, aproximarea putand fi facuta la O(N).

Cerinta 3 (corectarea textului):
Dictionarul este pastrat sub forma unui array de  structuri  alocat  dinamic, in
functie de numarul de cuvinte necesar. Sirul este impartit in cuvinte, avand  ca
delimitator caracterul spatiu (' '). Asadar, fiecare cuvant, pentru a  evita  ca
acesta sa fie corectat de 2 ori, va fi verificat in dictionarul existent, iar in
cazul in care acesta este intalnit, la sirul rezultat se va  atasa  varianta  sa
corecta. In cel mai rau  caz,  complexitatea  rezolvarii cerintei este O(N x M),
unde N este numarul de cuvinte din sir, iar M reprezinta dimensiunea  intregului
dictionar.

Cerinta 4:
Task 1) Construirea componentelor se face liniar, avand complexitatea O(N), unde
N este lungimea sirului. La parcurgerea acestuia, cu fiecare element gasit  este
actualizata componenta curenta, in cazul in care acesta este diferit  de  0, iar
ulterior este adaugata in array-ul ce retine componentele.
Task 2) Afisarea componentelor se face in O(N), unde N reprezinta numarul  total
al componentelor. Acestea au fost detectate anterior, la task-ul 1.
Task 3) Componenta maxima si indexul sau sunt  detectate  odata  cu  construirea
array-ului de componente. Odata intalnita o componenta, aceasta  este  comparata
cu cea mai mare componenta gasita pana la momentul respectiv, urmand ulterior sa
fie actualizata. Astfel, eficienta este  imbunatatita,  nefiind  necesara  nicio
parcurgere suplimentara.
Task 4) Pentru a verifica daca mesajul transmis este prim, vom calcula  cel  mai
mare divizor comun al elementelor, doua cate doua. In acest  mod,  complexitatea
rezolvarii  v a fi  O(N + (N - 1) + (N - 2) + ... + 1),  care  este  aceeasi  cu
O(N * (N + 1) / 2). Asadar, complexitatea se va reduce, in cel mai rau caz, la a
fi aproximativ O(N ^ 2).
Task 5) Odata cu parcurgerea fiecarui element calculam numarul caracterelor '#',
cat si suma tuturor caracterelor, lucru ce va ajuta sa determinam  daca  mesajul
este perfect. In cazul in care rezultatul  este  fals,  rezolvarea  cerintei  nu
necesita decat o singura operatie, afisarea cifrei '0'. In cazul in care mesajul
este prim, printr-o noua parcurgere, asemanatoare construirii  componentelor  de
la task-ul 1 se va construi un nou array alocat dinamic, ce stocheaza grupurile.
Astfel se obtine  o  complexitate  liniara,  O(N),  N  fiind  lungimea  sirului.
Sortarea elementelor se face folosind functia "qsort()", cu  o  complexitate  de
O(N * log(N)), unde N reprezinta numarul componentelor.