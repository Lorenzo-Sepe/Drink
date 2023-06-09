#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
// sudo apt-get install libpq-dev
// gcc Servermain.c -o pippo -I/usr/include/postgresql -lpq
int main() {
   PGconn *conn;
   PGresult *res;
   char *port;
   char *address, *user, *password, *database, *query, *insert_query;
   
    // Alloca la memoria per le stringhe
    address = (char *) malloc(100 * sizeof(char));
   printf("Inserisci l'indirizzo del server PostgreSQL: ");
   scanf("%s", address);
    
    port = (char *) malloc(100 * sizeof(char));
   printf("Inserisci la porta del server PostgreSQL: ");
   scanf("%s", port);
   
    database = (char *) malloc(100 * sizeof(char));
   printf("Inserisci il nome del database: ");
   scanf("%s", database);
   
    user = (char *) malloc(100 * sizeof(char));
   printf("Inserisci il nome utente: ");
   scanf("%s", user);
   
    password = (char *) malloc(100 * sizeof(char));
   printf("Inserisci la password: ");
   scanf("%s", password);//porva push
   
   // Connessione al database
   conn = PQsetdbLogin(address, port, NULL, NULL, database, user, password);
   
   // Controllo la connessione
   if (PQstatus(conn) != CONNECTION_OK) {
      printf("Errore di connessione: %s", PQerrorMessage(conn));
      PQfinish(conn);
      exit(1);
   }
   
   // Query per stampare tutti i drink
   query = "SELECT id, nome FROM drink";
   res = PQexec(conn, query);
   
   // Controllo la query
   if (PQresultStatus(res) != PGRES_TUPLES_OK) {
      printf("Errore nella query: %s", PQerrorMessage(conn));
      PQclear(res);
      PQfinish(conn);
      exit(1);
   }
   
   // Stampa i risultati
   int rows = PQntuples(res);
   int cols = PQnfields(res);
   
   printf("\nRisultati della query:\n");
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         printf("%s\t", PQgetvalue(res, i, j));
      }
      printf("\n");
   }
   
   // Libera la memoria
   PQclear(res);
   
   // Query per l'istruzione di inserimento fornita dall'utente
   printf("\nInserisci la query per l'istruzione di inserimento: ");
   scanf(" %[^\n]", insert_query);
   
   // Esegue l'istruzione di inserimento
   res = PQexec(conn, insert_query);
   
   // Controllo l'istruzione di inserimento
   if (PQresultStatus(res) != PGRES_COMMAND_OK) {
      printf("Errore nell'istruzione di inserimento: %s", PQerrorMessage(conn));
      PQclear(res);
      PQfinish(conn);
      exit(1);
   }
   
   // Stampa il messaggio di conferma
   printf("\nIstruzione di inserimento eseguita con successo.\n");
   
   // Libera la memoria
   PQclear(res);
   
   // Chiude la connessione
   PQfinish(conn);
   
   return 0;
}
