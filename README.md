# E-Index GUI

# Intro
E-Index to aplikacja bazodanowa, która jest okrojoną wersją e-dziennika. Miała to być prosta aplikacja okienkowa na zaliczenie przedmiotu, ale przerodziła się w projekt hobbystyczny, który ostatecznie został wykonany w celu przetestowania samego siebie. Aplikacja składa się z panelu logowania/rejestracji, panelu admina oraz po zalogowaniu, widoku ucznia i nauczyciela. Wszelkie dodatkowe okienka poza wyżej wymienionymi zostały stworzone jako widgety. Baza danych została wykonana na plikach binarnych, ze względu na warunki jakie zostały mi narzucone.

# Panel ucznia
Po zalogowaniu uczeń w swoim panelu może sprawdzić zdobyte oceny, nieobecności, średnią z każdego przedmiotu oraz kalendarz z nadchodzącymi testami (dni, w których ma być test są zaznaczone żółtym kolorem).

# Panel nauczyciela
Nauczyciel ma podgląd na wszystkie klasy i ich uczniów. Posiada możliwość dodawania ocen, niebecności oraz testów.

# Admin mode
Admin mode to dodatkowy panel, do którego można wejść tylko poprzez uruchomienie aplikacji z argumentem "admin". Admin ma wgląd na wszystkich zarejestrowanych użytkowników oraz ich dane. Ponadto ma możliwość tworzenia nowych kont uczniów/nauczycieli, edycji istniejących kont oraz ich usuwania.
