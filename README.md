# Labor 2

Alle Laboreinheiten sind in 2 Teile aufgeteilt:

**1. Teil** (30min): Ausarbeitung von Programmieraufgaben (Angaben und Abgaben über TUWEL). Ihre Lösungen werden nachträglich bewertet.

**2. Teil** (120min): Sie erarbeiten sich selbständig (Diskussionen unter Studierenden sind erlaubt und erwünscht) die vorgegeben Aufgabenstellungen. Sie können jederzeit Fragen stellen. Ziel ist es, dass Sie die unter **Demonstration** vorgegebenen Arbeitschritte und Aufgaben lösen.
Sobald Sie sich in der Lage fühlen, diese Arbeitschritte und Aufgaben zu demonstrieren, rufen Sie bitte einen Betreuer zu Ihrem Arbeitsplatz.

---

# 1. Teil (30min): Bewertete Programmieraufgaben

 ***Aufgabenstellung über TUWEL:*** "Hausübung 1, Teil B"

# 2. Teil (120min): Labor mit dem Schwerpunkt auf der "verschachtelten" Verwendung von dynamischem Speicher. Weitere Themen: Komplexität von Operationen auf Datenstrukturen und dem Vergleich von Fließkommazahlen

**Hinweis:** Nutzen Sie die Gelegenheit bei den Laborterminen bitte auch, um Ihre Fragen im Hinblick auf das Programmieren in C oder auch allgemeinerer Art zu stellen!

# Demonstration

0. Laden Sie sich Angabe (samt Quelldateien) als `.zip`-Datei herunter und entpacken Sie diese.

1. **Vector: Ebenen von dynamischem Speicher:** Im Ordner `vector` befindet drei Quelldateien die jeweils mit einer `struct Vector`-Struktur arbeiten:

    - `vector1.c`: keine dynamischen Allokationen, alles als lokale Variablen.
    - `vector2_dynamic_data.c`: dynamische Allokation für die Elemente des Vectors.
    - `vector3_dynamic_vector.c`: dynamische Allokation für den Vector selbst und die Elemente.

    Ziel der Aufgabe ist es, das Sie den Umgang mit dynamischen Ressourcen und den Unterschied zu und das Zusammenwirken mit lokalen Variablen einüben. **Details zur Aufgabenstellungen befinden sich jeweils in der Quelldatei**. 
    Diskutieren Sie mit Ihren Sitznachbarn, welche Vor- und Nachteile/Limitierungen die drei skizzierten Implementierungsansätze haben. Notieren Sie sich Stichpunkte Ihrer Diskussion in die jeweilige Quelldatei.

2. **Liste: Ebenen von dynamischem Speicher:** Im Ordner `list` befindet sich eine Header-Datei `List.h` die eine `struktur List` sowie eine zugeörige Funkton `list_invariants` enthält. Diese Header-Datei wird in jede der drei Quelldateien eingebungen:

    - `list1.c`: keine dynamischen Allokationen.
    - `list2_dynamic_nodes.c`: dynamische Allokation für die Knoten der Liste.
    - `list3_dynamic_list.c`: dynamische Allokation für die Liste selbst und die Knoten.

    Gehen Sie wei Punkt 1. (Vector) vor und bearbeiten Sie die **Aufgabenstellungen in jeder der drei Quelldateien**. Diskutieren Sie ebenfalls mit Ihren Sitznachbarn, welche Vor- und Nachteile/Limitierungen der drei Implementierungsansätze. Notieren Sie sich Stichpunkte Ihrer Diskussion in die jeweilige Quelldatei.

3. **Komplexität von Operationen auf Datenstrukturen:** Diskutieren Sie mit Ihren Sitznachbarn **wie viel "Arbeit"** zu tun ist (sprich: welche Operationen werden auf Datenebenen nötig), wenn Sie ein Element in einen Vector oder eine Liste an beliebiger (aber bereits bekannter) Stelle **einfügen oder entfernen**. Ihre Überlegungen sollten jedenfalls auch die aktuelle Länge des Vectors/der Liste miteinbeziehen. 
Hinweise:

    - Nehmen Sie eine Implementierung für Vector und die Liste vergleichbar zu Punkt 1./2. an.
    - Erinnern Sie sich an Ihre Implementierung von `vector_insert_before` aus Hausübung 1.
    - Wieviele Daten müssen mindestens/höchstens kopiert (oder gelesen) werden, gibt es eine Abhängigkeit von der aktuellen Anzahl an Elementen, bzw. der Position an der eingefügt wird?
    - Können Sie Aussagen machen, unter welchen Anwendungsbedingungen/Zugriffsmustern das Einfügen/Entfernen in einen Vector oder eine Liste vorteilhaft ist?

    Hinweis: Machen Sie sich auf einem Blatt Papier oder in einer Datei stichpunktartige Notizen zu Ihrer Diskussion.

3. **Fließkommazahlen verleichen:** Im Ordner `compare` befinden sich 4 Quelldateien, in denen jeweils mit einer Vergleichsfunktion zwei `float`-Werte verglichen werden:

    - `compare1_bitequal.c`: bitweise Vergleich/exakter Vergleich.
    - `compare2_abseps.c`: Vergleich mittels fester Toleranz für die absolute Differenz. 
    - `compare3_releps.c`: Vergleich mittels fester Toleranz für die relative Differenz. 
    - `compare4_releps_cancellation.c`: Zeigt Probleme auf, die bei Auslöschung (*catastropic cancellation*) auftreten: die relative Differenz verliert die Aussagekraft.         

    Beachten Sie, dass in jeder Datei die Werte, die verglichen werden, auch skaliert werden:

    - Vergleich von Werten nahe `1`
    - Vergleich von Werten nahe `1e10`
    - Vergleich von Werten nahe `1e-10`    

    Komplieren Sie alle Quelldateien und betrachen Sie die Ergebnisse fuer die Vergleiche in der Konsolenausgabe. Diskutieren Sie die Ergebnisse fuer jede Quelldatei mit Ihren Sitznachbarn und machen Sie sich Notizen zu ihrer Diskussion:

    - `compare_bitequal()`: Warum ist diese Vergleichsfunktion für die meisten Anwendungen nicht ausreichend?
    - `compare_abseps()`: Warum nicht ausreichend, wenn ein großer Wertebereich abgedeckt werden sollen?    
    - `compare_releps()`: Warum nicht geeignet für Werten denen eine Auslöschung vorhergeht? 
    
---
