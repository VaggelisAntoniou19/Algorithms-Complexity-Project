# Algorithms-Complexity-Project 2020-2021

## Αλγόριθμοι χρωματισμού γραφημάτων
 
Τα προβλήματα χρωματισμού γραφήματος είναι προβλήματα συνδυαστικής βελτιστοποίησης κατηγορίας **NP‐hard** [Richard M Karp.]. Η υλοποίηση αυτών των προβλημάτων αφορά την ανάθεση ενός
χρώματος σε κάθε κορυφή ενός γραφήματος, όπου το κύριο χαρακτηριστικό είναι γειτονικές κορυφές να χρωματίζονται με διαφορετικό χρώμα (όπως στο Σχήμα 1), ενώ ακόμη ένας περιορισμός 
είναι η χρήση ελάχιστου αριθμού διαφορετικών χρωμάτων. Στην παρούσα εργασία ζητείται η υλοποίηση τεσσάρων αλγορίθμων χρωματισμού γραφημάτων και η εφαρμογή τους σε γνωστά προβλήματα.

## Περιγραφή Προβλήματος

Το πρόβλημα χρωματισμού γραφήματος τυπικά ορίζεται ως εξής. Δεδομένου ενός μη κατευθυνόμενου απλού γραφήματος G = (V, E) με ένα σύνολο κορυφών V και ένα σύνολο ακμών E, ζητείται η ανάθεση σε κάθε κορυφή v ∈ V ενός ακεραίου c(v) ∈ {1, 2, ..., k} έτσι ώστε το k να ελαχιστοποιείται και να ισχύει ότι c(v) ≠ c(u) ∀{v, u} ∈ E.

![graph_image](https://user-images.githubusercontent.com/73305651/98444708-d5d0da00-211b-11eb-8b03-17ac6b1d8107.png)


Οι αλγόριθμοι που θα εξεταστούν και θα πραγματοποιηθεί η υλοποίησή τους είναι οι εξής:

### Ο αλγόριθμος First Fit

Ο αλγόριθμος First Fit είναι η πρώτη εφαρμογή χρωματισμού γραφημάτων στην παρούσα εργασία η οποία λαμβάνει υπόψη μια κορυφή κάθε φορά με κάποια σειρά και εκχωρεί σε κάθε κορυφή τον λιγότερο από τους θετικούς ακέραιους αριθμούς που δεν χρησιμοποιείται από κάποιον γείτονα. Επίσης ο μέγιστος αριθμός χρωμάτων που χρησιμοποιούνται στο γράφημα με τον αλγόριθμο First Fit σε όλες τις κορυφές δηλώνεται [H.A. Kierstead].

### O αλγόριθμος DSATUR

Ο DSatur είναι ένας ευρετικός αλγόριθμος χρωματισμού γραφημάτων (heuristic graph colouring algorithm), όπου παράγει ακριβή αποτελέσματα αλγορίθμου χρωματισμού γραφημάτων και προτάθη- κε από τον Daniel Brélaz το 1979. Είναι η δεύτερη εφαρμογή χρωματισμού γραφημάτων στην παρούσα εργασία η οποία λαμβάνει να χρωματίζει τις κορυφές ενός γραφήματος την μία μετά την άλλη, ξοδεύοντας ένα αχρησιμοποίητο χρώμα όταν χρειάζεται. Μόλις χρωματιστεί μια νέα κορυφή, ο αλγόριθμος καθορίζει ποιες από τις υπόλοιπες άχρωμες κορυφές έχει τον υψηλότερο αριθμό χρωμάτων στη γειτονική του περιοχή και στη συνέχεια χρωματίζει αυτήν την κορυφή. Ο Brélaz ορίζει αυτόν τον αριθμό ως τον βαθμό κορεσμού (degree of saturation) μιας δεδομένης κορυφής. Το όνομα του αλγορίθμου προέρχεται από την συστολή του βαθμού κορεσμού [Brélaz, Daniel].  

### O αλγόριθμος Recursive Largest First

Ο αλγόριθμος Recursive Largest First (RLF) είναι η τρίτη εφαρμογή αλγορίθμου της παρούσας εργασίας και είναι ένας από τους πιο δημοφιλείς άπληστους ευρετικούς (greedy heuristics) αλγορίθμους χρωματισμού κορυφής. Δημιουργεί διαδοχικά κλάσεις χρωμάτων με βάση τις άπληστες επιλογές, δηλαδή η πρώτη κορυφή που τοποθετείται σε μια έγχρωμη κλάση C είναι μία κορυφή με τον μέγιστο αριθμό άχρωμων γειτόνων. Οι επόμενες κορυφές που τοποθετούνται στην κατηγορία C επιλέγονται με τρόπο τέτοιο ώστε να έχουν τόσους πολύχρωμους γείτονες όπου δεν μπορούν να τοποθετηθούν στην κλάση C [Mourchid Adegbindin].

### O αλγόριθμος backtracking DSATUR.

O αλγόριθμος backtracking DSATUR είναι η τέταρτη εφαρμογή αλγορίθμου της παρούσας εργασίας, με κύριο χαρακτηριστικό την εκχώρηση χρωμάτων σε όλες τις κορυφές του γραφήματος με σκοπό τον χρωματισμό του. Δεδομένου ενός μη κατευθυνόμενου γραφήματος και ενός ακεραίου αριθμού m, καθορίζεται εάν το γράφημα μπορεί να χρωματιστεί με το πολύ m χρώματα, έτσι ώστε να μην χρωματίζονται δύο γειτονικές κορυφές του γραφήματος με το ίδιο χρώμα. Εδώ ο χρωματισμός ενός γραφήματος σημαίνει την εκχώρηση χρωμάτων σε όλες τις κορυφές. Η αρχική σειρά των κορυφών καθορίζεται από τον αλγόριθμο DSATUR. Ως εκ τούτου, οι κορυφές με τα λιγότερα διαθέσιμα χρώματα χρωματίζονται πρώτα, με τους δεσμούς να σπάζουν με βάση των βαθμών (degrees) και οι περαιτέρω δεσμοί να σπάζουν τυχαία. Αφού εκτελεστεί ένα βήμα προς τα πίσω, οι κορυφές αναδιατάσσονται δυναμικά, έτσι ώστε η επόμενη κορυφή που πρέπει να χρωματιστεί να είναι και αυτή με τα λιγότερα διαθέσιμα χρώματα. Εάν η κορυφή δεν διαθέτει εφικτά χρώματα, ο αλγόριθμος παίρνει ένα ακόμη βήμα προς τα πίσω (Backtracking) [R.M.R. Lewis].

### Πρόβλημα χρονοπρογραμματισμού εξετάσεων

Το πρόβλημα χρονοπρογραμματισμού εξετάσεων αφορά φοιτητές που έχουν πραγματοποιήσει εγγραφές σε εξετάσεις μαθημάτων. Για κάθε εξέταση διατίθεται μια λίστα από φοιτητές και κάθε φοιτητής μπορεί να είναι εγγεγραμμένος σε μια ή περισσότερες εξετάσεις. Κάθε εξέταση θα πρέπει να τοποθετηθεί σε μια περίοδο εξέτασης και η λύση του προβλήματος συνίσταται στην ανά- θεση όλων των εξετάσεων στο μικρότερο δυνατό αριθμό περιόδων έτσι ώστε να μην υπάρχουν συγκρούσεις, δηλαδή να μην υπάρχουν φοιτητές που θα έπρεπε να συμμετάσχουν σε εξετάσεις σε περισσότερα του ενός μαθήματα στην ίδια περίοδο. Ως δεδομένα του προβλήματος θα χρησιμοποιηθούν τα δεδομένα του προβλήματος χρονοπρογραμματισμού εξετάσεων Toronto τα οποία είναι δια- θέσιμα προς μεταφόρτωση στη διεύθυνση https://github.com/VaggelisAntoniou19/Algorithms-Complexity-Project.git Τα δεδομένα Toronto αποτελούνται από 13 προβλήματα και πληροφορίες για κάθε πρό- βλημα παρουσιάζονται στον Πίνακα 1. Τα αρχεία δεδομένων στα οποία υπάρχει η κατάληξη .stu διαθέτουν για κάθε σπουδαστή μια γραμμή που περιέχει τους αριθμούς των μαθημάτων στα οποία είναι εγγεγραμμένος χωρισμένους μεταξύ τους με κενά. Η πρώτη γραμμή του αρχείου αντιστοιχεί στον πρώτο σπουδαστή, η δεύτερη γραμμή στο δεύτερο σπουδαστή κ.ο.κ. Για παράδειγμα το αρχ- είο **car‐f‐92.stu** περιέχει 18419 σειρές δεδομένων και ξεκινά με τις ακόλουθες σειρές:

+ 0170
+ 0156
+ 0281
+ 0006
+ 0154 0156
+ 0383
+ 0534 0535 0536
+ 0275
+ 0091 0160 0164
+ ...

που σημαίνουν ότι ο φοιτητής 1 έχει εγγραφεί στο μάθημα 0170, ο φοιτητής 2 έχει εγγραφεί
στο μάθημα 0156, ο φοιτητής 3 έχει εγγραφεί στο μάθημα 0281, ο φοιτητής 4 έχει εγγραφεί στο
μάθημα 0006, κ.ο.κ


![table](https://user-images.githubusercontent.com/73305651/98452435-05053c80-2158-11eb-9c6a-1a6fc1541459.png)

*Θεωρώντας κάθε εξέταση ως κόμβο ενός γραφήματος και κάθε ακμή ανάμεσα σε δύο κόμβους να υποδηλώνει την ύπαρξη κοινών φοιτητών ανάμεσα στις δύο εξετάσεις που βρίσκονται στα άκρα της ακμής, το πρόβλημα μπορεί να θεωρηθεί ως πρόβλημα χρωματισμού γραφήματος όπου κάθε χρώμα είναι και μια περίοδος εξέτασης.*

## Βιβλιογραφία

Brélaz, Daniel (1979-04-01). "New methods to color the vertices of a graph". Communications of the ACM. 22 (4): 251–256. doi:10.1145/359094.359101. ISSN 0001-0782.

H.A. Kierstead, David A. Smith, W.T.Trotterb (2016-01-15). "European Journal of Combinatorics"."First-fit coloring on interval graphs has performance ratio at least 5".pp(236-254).

Richard M Karp (1972). "Complexity of computer computations". "chapter reducibility among combinatorial problems". Plenum Press. "Survey of State‐of‐the‐Art". pp(23:85–104).

Mourchid Adegbindin, Alain Hertz, Martine Bella ̈ıche (2015-11-02). "A new efficient RLF-like Algorithmfor the Vertex Coloring Problem".pp(1-2).

R.M.R. Lewis (2015-10-27)."A Guide to Graph ColouringAlgorithms and Applications"."Algorithm Case Studies".pp(88-89).
 
 
