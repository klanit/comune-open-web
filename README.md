# WebPA 


WebPA è l'evoluzione del progetto che ha ideato e sviluppato <a href="https://www.klan.it">Klan.IT</a> una piattaforma conforme alle nuove <a class="XqQF9c" href="https://www.google.com/url?q=https%3A%2F%2Fdocs.italia.it%2Fitalia%2Fdesigners-italia%2Fdesign-linee-guida-docs%2Fit%2Fstabile%2Findex.html&amp;sa=D&amp;sntz=1&amp;usg=AFQjCNHvpOY6rd3bcMGG6I9e5PrmByqzdw" target="_blank">linee guida AGID</a>


## Descrizione

WebPA permette alle amministrazioni pubbliche di utilizzare una piattaforma CMS conforme alle normative vigenti, accessibile e in linea con le direttive AgID.
I redattori (funzionari, dirigenti, amministrazioni, associazioni) possono inserire e organizzare facilmente i contenuti, che saranno visualizzati anche con calendari, mappe, elenchi di documenti.

## Altri riferimenti

Per maggiori informazioni è possibile consultare: 

 * [Demo](https://agid2.klan.it/)
 * [Manuale utente](https://sites.google.com/view/agidpercomuni-guida/home)


## Project Status

Il prodotto è *stabile* e *production ready* e usato in produzione in diverse città Italiane. Lo sviluppo avviene in modo costante, sia su richiesta degli Enti utilizzatori, sia su iniziativa autonoma del _maintainer_.

## Informazioni tecniche

L'applicazione è sviluppata come personalizzazione del CMS Drupal 7 e consta di codice PHP, il dump del database contenente una installazione pienamente funzionante dell'applicativo comprensiva della struttura interna di navigazione.

### Struttura del Repository

Il repository contiene i seguenti file:


Le directory
```
/dfs/var/prototipo
/var
```
contengono invece le risorse statiche minime necessarie all'applicazione (loghi, elementi grafici generali, etc...).


```
/sql
```
La directory SQL contiene un dump del database PostgreSQL configurato e pronto all'uso.

Il file `Dockerfile` e le directory
```
/scripts
/conf.d
```
contengono file di supporto per la creazione dell'immagine Docker dell'applicativo.

Il file
```
docker-compose.yml
```
contiene i servizi minimi necessari per l'esecuzione di Comunweb e può essere usato per il deploy su un singolo host o su un cluster Docker Swarm o Kubernetes.

Il file
```
docker-compose.override.yml
```
viene usato automaticamente da docker-compose quando e' disponibile: quando si clona il repository ad esempio e si hanno tutti i file a disposizione, questo aggiunge alcuni servizi di supporto utili in ambiente di sviluppo, come una interfaccia web per il database.


### Requisiti

Lo stack minimo di Comunweb è il seguente:
  * database PostgreSQL 9.6
  * PHP 7.2
  * Solr 4.10.x per il motore di ricerca

Nel file `docker-compose.yml` vengono inoltre utilizzati:
  * Varnish per la cache dei contenuti
  * Traefik per il routing tra i diversi container

Le dipendenze del sistema operativo sono risolte nell'immagine da cui origina
l'immagine di Comunweb, ovvero [opencontentcoop/ezpublish](https://hub.docker.com/r/opencontentcoop/ezpublish). Per i dettagli su questa immagine si rimanda
al [repository](https://www.github.com/OpencontentCoop/docker-ezpublish) ad essa dedicata.

### Come si esegue la build del repository

Con il comando che segue:

    docker build -t opencity .

si esegue la build dell'immagine docker dell'applicazione: vengono installate le dipendenze
del sistema operativo e successivamente composer e le dipendenze applicative.

### Local docker environment

Per avere un ambiente completo di demo o di sviluppo clonare
il repository e dalla directory principale dare i comandi:

```
sudo chown 8983 conf.d/solr/prototipo/* -R
docker-compose up -d
docker-compose exec php bash -c 'cd html; php bin/php/updatesearchindex.php -s bootstrapitalia_backend --allow-root-user'
```

Il prototipo di Comunweb sarà disponibile ai seguenti indirizzi:

* [opencity.localtest.me](https://opencity.localtest.me)
* [opencity.localtest.me/backend](https://opencity.localtest.me/backend), per l'area riservata ai redattori e amministratori (l'utente di default con cui si accede è `admin/admin`)
* [solr.localtest.me/solr](https://solr.localtest.me/solr), per l'interfaccia amministrativa di SOLR
* [traefik.localtest.me:8080](https://traefik.localtest.me:8080) per l'interfaccia amministrativa di Traefik
* [Mailhog](https://mailhog.opencity.localtest.me/), le email inviate in questo ambiente sono visibili in questa interfaccia web
* [PgWeb](https://pgweb.opencity.localtest.me/), interfaccia web per il database PostgreSQL

Il certificato usato per tutti i domini è un wildcard self-signed certificate sul dominio *.localtest.me, quindi al primo collegamento si ottiene un warning.

### Useful commands

Per vedere i log di tutti container:

    docker-compose logs -f --tail 20

o solo uno di essi (ad esempio php):

    docker-compose logs -f --tail 20 php

Per ottenere una shell all'interno del container PHP, eseguire:

    docker-compose exec php bash

Per accedere al database da CLI:

    docker-compose exec postgres bash
    bash-4.4# psql -v ON_ERROR_STOP=1 --username "$POSTGRES_USER" --dbname "$POSTGRES_DB"

Per aggiornare il dump del database nella cartella `sql`:

    docker-compose exec postgres bash
    bash-4.4# pg_dump -U ${POSTGRES_USER} $POSTGRES_DB | gzip > /docker-entrypoint-initdb.d/${POSTGRES_DB}.sql.gz

Per reindicizzare tutti i contenuti su SOLR:

    docker-compose exec php bash -c 'cd html; php bin/php/updatesearchindex.php -s bootstrapitalia_backend --allow-root-user'

### Rebuild database from scratch

Per ricreare il database dai dump del repository e tornare quindi al prototipo orginale è necessario spegnere il db, 
rimuovere il volume del container db e riavviare il database

    docker-compose stop postgres; \
    docker-compose rm postgres; \
    docker volume rm opencity_pgdata; \
    docker-compose up -d postgres

Attenzione: il nome del volume dipende dalla directory in cui avete fatto il clone, se non è `opencity` è necessario adattare il comando precedente.

### Continuous Integration

Il software ha una pipeline di CI, che esegue una build ad ogni commit, disponibile alla seguente url:

https://gitlab.com/opencontent/opencity/pipelines

Le build delle immagini docker sono disponibili nel [Registry](https://gitlab.com/opencontent/opencity/container_registry) di GitLab.

### Deploy in produzione

Per il deploy in un ambiente di produzione è necessario configurare diversi elementi: in generale
tutte le configurazioni si trovano nei file `conf.d/override/<file>.ini.append.php`, si indicano comunque
di seguito alcuni punti di sicuro interesse. 
In particolare sarà necessario intervenire su:
  * [Dominio](/conf.d/ez/override/site.ini.append.php#L96-97)
  * [Server di posta](/conf.d/ez/override/site.ini.append.php#L103-113)

## Copyright (C)

Il titolare del software è il [Comune di Ala](https://www.comune.ala.tn.it).

Il software è rilasciato con licenza aperta ai sensi dell'art. 69 comma 1 del [Codice dell’Amministrazione Digitale](https://cad.readthedocs.io/)

### Maintainer

[Opencontent SCARL](https://www.opencontent.it/), è responsabile della progettazione, realizzazione e manutenzione tecnica di Comunweb

