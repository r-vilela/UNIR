# How to run the DataBase

I'm using a postgres image to use on the lessons.

```
docke compose up -d
```

To access the database I use the psql.

```
psql -h localhost -p 5432 -U student -d labdados
```
