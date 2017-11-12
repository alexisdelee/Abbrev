# Abbrev

Au lieu d'afficher la référence complète de n octets, cet outil permet la détermination de références partielles, k,  les plus courtes possibles et non ambiguës, tels que :  

 - commit.entropy <= k <= n où k est la référence et n = strlen(référence) 
 - 1 <= commit.entropy <= n, par défaut commit.entropy vaut 7 mais sa valeur peut être redéfinie 
 - il ne peut exister qu'une seule et unique référence k 

## Example

Ajoutons les valeurs suivantes grâce à la fonction commit.add :  

 - a94a8fe5ccb19ba61c4c0873d391e987982fbbd3 
 - a94a8fe5ccb18ba61c4c0873d391e987982fbbd3 
 - aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d 
 - 697bc46e1beaa1667601998bc72be435e5f8666f 
 - 7c211433f02071597741e6ff5a8ea34789abbf43 
 - 1edbf3da8cde6b893130354e79ba15fca2269959 

L'arbre suivant est ainsi généré :  


```
.
|-- a94a8fe5ccb1 
|              |-- 9ba61c4c0873d391e987982fbbd3 
|              `-- 8ba61c4c0873d391e987982fbbd3 
|-- aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d 
|-- 697bc46e1beaa1667601998bc72be435e5f8666f 
|-- 7c211433f02071597741e6ff5a8ea34789abbf43 
`-- 1edbf3da8cde6b893130354e79ba15fca2269959 
```

Si nous faisons une recherche (commit.abbrev) sur les valeurs suivantes, voyons les résultats qui en ressortent :  

 - 697bc46e1beaa1667601998bc72be435e5f8666f => 697bc46 
 - 1edbf3da8cde6b893130354e79ba15fca2269959 => 1edbf3d 
 - a94a8fe5ccb19ba61c4c0873d391e987982fbbd3 => a94a8fe5ccb19 