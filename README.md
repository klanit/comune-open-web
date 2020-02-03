# Comune Open Web 


Comune Open Web è l'evoluzione del progetto che ha ideato e sviluppato <a href="https://www.klan.it">Klan.IT</a> una piattaforma conforme alle nuove <a class="XqQF9c" href="https://www.google.com/url?q=https%3A%2F%2Fdocs.italia.it%2Fitalia%2Fdesigners-italia%2Fdesign-linee-guida-docs%2Fit%2Fstabile%2Findex.html&amp;sa=D&amp;sntz=1&amp;usg=AFQjCNHvpOY6rd3bcMGG6I9e5PrmByqzdw" target="_blank">linee guida AGID</a>

## Riferimenti

Questo progetto nasce come evoluzione del progetto <a href="https://github.com/piattaformeweb/drupalcsi">"CMS Drupal 7 per i siti web dei comuni"</a> applicando le nuove <a href="https://docs.google.com/spreadsheets/d/1bE0Ns0LsU0VDvCBT1WXZ5_yIxJU5AbUYcu_F8yMfpHQ/edit#gid=1225072581">linee guida dell'architettura dell'informazione dei siti web dei comuni italiani</a> redatte dal Team per la Trasformazione Digitale - <a href="https://designers.italia.it">Designers Italia</a>.


## Framework utilizzato

Drupal 7.69

## Librerie incluse

Le seguenti librerie o componenti sono già incluse nel pacchetto distribuito:

Framework CSS: Bootstrap 3.3.x

Font: Font Titillium Web, Font Awesome 4.7.x

Framework JS : JQuery 1.x (fornito con Drupal)

Plugin JS: CKEditor 4.5.x, JQuery Easing 1.3, Plupload 1.5.8, Masonry 3.3.2,jQuery Images Loaded	4.1, jQuery Masonry	3.3.2, jQuery Update	jQuery 1.10.2, jQuery UI 1.10.2, TCPDF Library version.


## Descrizione

Comune Open Web permette alle amministrazioni pubbliche di utilizzare una piattaforma CMS conforme alle normative vigenti, accessibile e in linea con le direttive AgID.
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
/site/default/settings.php

```
contiene le configurazioni necessarie alla connessione con il database. Occorre modificare il nome del proprio database, lo username, la password e l'host su cui risiede il database.

```
/sql
```
La directory SQL contiene un dump del database Mysql configurato e pronto all'uso.



### Requisiti

Lo stack minimo di WebPA è il seguente:
  * database Mysql 5.7.28
  * PHP 7.1


Il prototipo di Comune Open Web sarà disponibile ai seguenti indirizzi:

* [agid2.klan.it/](https://agid2.klan.it/)


La connessione è criptata tramite protocollo di cifratura TLS
## Account demo

* Username: admin
* Password: Zfq?3&Z.mcs

* Username: Responsabile
* Password: nSMDyh.%P2G

### Deploy in produzione

Per il deploy in un ambiente di produzione è necessario configurare diversi elementi: in generale
tutte le configurazioni si trovano nei file `site/default/settings.php`.

## Copyright (C)

Il titolare del software è il [Klan.IT S.r.l.](https://www.klan.it).

Il software è rilasciato con licenza aperta ai sensi dell'art. 69 comma 1 del [Codice dell’Amministrazione Digitale]

### Maintainer

[Klan.IT S.r.l.](https://www.klan.it/), è responsabile della progettazione, realizzazione e manutenzione tecnica di WebPA

