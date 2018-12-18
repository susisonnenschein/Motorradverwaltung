# Motorradverwaltung

Aufgabenstellung war:

Sie sind für die Verwaltung von Motorrädern zuständig. Da zurzeit alle Vorgänge in Papierform festgehalten werden, 
sollen Sie ein Programm zur Motorradverwaltung erstellen.
Die Mitarbeiterin soll die Möglichkeit haben, die Kunden zu verwalten und Reservierungen der Motorräder vorzunehmen. 
Der Kunde kann nur jeweils ein Motorrad reservieren. Es gibt insgesamt 4 Motorräder zur Auswahl: „Suzuki Bandit“, 
„Honda TransAlp“, „BMW F 650 GS“ und „Kawasaki ZZR1400“. Stellen Sie sicher, dass ein Motorrad nicht doppelt reserviert wird. 
Bei der Reservierung muss der Kunde: Name, Vorname, Adresse (Straße, Nr. PLZ, Ort), Geburtsjahr, Telefonnummer und ob er 
Führerschein der Klasse A besitzt, angeben. Besitzt er kein Führerschein der Klasse A, so kann kein Motorrad für ihn reserviert 
werden. Sobald die Übergabe des Motorrads erfolgt ist, wird die Reservierung für diesen Kunden storniert. Der aktuelle Stand von
„heute“ soll in die Datei „reservierungen.txt“ geschrieben werden.

Das Programm soll mindestens folgende Anforderungen erfüllen:

Verwaltung der Kunden:

    Daten erfassen. Die Erfassung der Daten soll über istream (>>) Operatorüberladung erfolgen.
    Alle Kundendaten ausgeben. Die Ausgabe soll über ostream (<<) Operatorüberladung erfolgen.


Verwaltung der Reservierungen:

    Reservierung vornehmen
    Motorrad herausgeben (mit der Abfrage des Kundenvor- und nachnamens)


Dateiverwaltung:

    Der aktuelle Stand der Reservierungen soll in die Datei „reservierungen.txt“ geschrieben werden. Falls die Datei noch nicht existiert soll sie angelegt werden, ansonsten sollen die Daten an das Ende der Datei angehängt werden. Lesen der Daten aus der Datei ist nicht gefordert!

 
Die Verwaltung der Kunden soll dynamisch erfolgen. Bei Bedarf sollen entsprechende (Fehler-) Meldungen ausgegeben werden. 

 
