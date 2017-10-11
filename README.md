# Mini-tutorial de git

### Sobre este tutorial:
Está orientado no a aprender a usar git, sino a _entender_ git. 
Para sacarle todo el jugo a este tutorial, conviene que te crees una cuenta en github (este sito), y _forkees_ este repositorio.
Caso contrario, solo podrás hacer la primer mitad de este tutorial.

### Comenzando
Para obtener el código de este ejercicio tendrás que hacer `git clone`, o bien de este repo(no recomendado), o bien del que hayas forkeado.
Partirás en la branch _master_, que es de donde salir si querés implementar esto por tu cuenta.

>Todo muy cheto, pero de qué me estás hablando?:

* git: es un programa de control de versiones (_vcs_) creado por Linus Torvalds (sí, el mismo que el de linux). Modela los archivos en un directorio, y las modificaciones de los mismos, como _commits_ en un _repositorio_.
Dichos commits forman un _directed acyclic graph_, es decir, tienen relaciones entre ellos. En esto se resume el modelo interno de git, que es hermosamente simple.
* commit: La unidad atómica de información trackeable en git. Almacena las diferencias de uno o mas archivos contra el commit anterior(su padre).
Tiene un identificador único.
* branch: es un commit con un nombre especial, y otros atributos que facilitan pensarlo como la rama de un proyecto. Hay varios commits con nombres especiales, como cada branch y HEAD.
* repositorio: Abreviado _repo_ por los chicos populares, es la entidad que agrupa muchos commits.
`git init` _inicializa_ un repo, y `git clone` trae un repo desde una ubicación remota.
El repo que tenés en tu computadora no tiene grandes diferencias con el que hay hosteado en github, o el que hay en mi computadora mientras preparo este tutorial.

### Checkout y branches
Para pasarse a otra branch:
```
git checkout branch_name # se pasan a la branch branch_name, que ya debe existir
```
Puede hacerse esto con la branch `resolucion_capurro`, para ver como lo resolví por mi cuenta, o con `resolucion_clase` para obtener el codigo de la resolucion de la clase.

Una vez que tenés las branches locales, podés cambiar entre ellas con `git checkout branch_name`.
```
git checkout resolucion_clase # Miran como se hizo algo en clase, por ejemplo, los header guards
git checkout master           # Vuelven a master, para empezar con su resolucion
```
Podés crear tus propias branches. Voy a asumir que tu nombre es Fabian
```
git checkout master #vuelvo a master si estaba en otra branch
git checkout -b resolucion_fabian
```
Muy bien Fabian, tenés tu propia branch!

#### Viendo la historia
Ahora, podés hacer cambios en tu branch, supongamos que refactorizás el código del comandante con una función `es_primo` y otros cambios para que no te haga daño a los ojos.
Podés pedirle a git que te muestre qué archivos cambiaste desde el ultimo commit:
```
 ~/ejercicio_biblioteca   resolucion_fabian ✚ 
 git status
On branch resolucion_fabian
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

	modified:   primos_comandante.c
```
`git status` nos dio un resumen del estado (duh!) del repo.
Entre su salida, se encuentra el branch actual y los cambios desde el último commit.
Para tener más información, por ejemplo de los commits padres del actual:
```
 ~/ejercicio_biblioteca   resolucion_fabian ✚ 
 git log
commit 81b4124ff32097f3d8309746d5cd354fb642fedb (HEAD -> resolucion_fabian, origin/master, origin/HEAD, master)
Author: juanpcapurro <juanpcapurro@gmail.com>
Date:   Tue Oct 3 20:41:15 2017 -0300

    commit del cual comenzar la clase, el programa anda pero produce ceguera
(END)
```
Da información sobre todos los commits del branch actual.
Para ver un log mas interesante, podríamos probar con alguna branch más larga.
```
 ~/ejercicio_biblioteca   resolucion_fabian ✚ 
 git checkout resolucion_capurro
error: Your local changes to the following files would be overwritten by checkout:
	primos_comandante.c
Please commit your changes or stash them before you switch branches.
Aborting
```
Whoops! No se puede cambiar a una branch en este estado, ya que no hay un commit que recuerde los cambios hechos.
Podría crearse un commit, pero git nos da una alternativa:
```
 ✘  ~/ejercicio_biblioteca   resolucion_fabian ✚ 
 git stash
Saved working directory and index state WIP on resolucion_fabian: 81b4124 commit del cual comenzar la clase, el programa anda pero produce ceguera
 ~/ejercicio_biblioteca   resolucion_fabian 
 ```
 _stash_ guarda las ediciones actuales, ya veremos cómo recuperarlos.
 ```
 git checkout resolucion_capurro
Switched to branch 'resolucion_capurro'
Your branch is up-to-date with 'origin/resolucion_capurro'. #ahora sí!
 ~/ejercicio_biblioteca   resolucion_capurro 
 git log
commit 69f525e97ffb33b3432af63b5f9097b1e8378a3a (HEAD -> resolucion_capurro, origin/resolucion_capurro)
Author: juanpcapurro <juanpcapurro@gmail.com>
Date:   Tue Oct 3 21:25:06 2017 -0300

    refactorizado en bibliotecas

commit ca70027a02133646ae1a86dab7a360f3d7613db6
Author: juanpcapurro <juanpcapurro@gmail.com>
Date:   Tue Oct 3 21:09:56 2017 -0300

    refactorizado y modularizado

commit 81b4124ff32097f3d8309746d5cd354fb642fedb (origin/master, origin/HEAD, resolucion_fabian, master)
Author: juanpcapurro <juanpcapurro@gmail.com>
Date:   Tue Oct 3 20:41:15 2017 -0300

    commit del cual comenzar la clase, el programa anda pero produce ceguera
```
Bueno, suficiente de chusmear qué tanto postergué preparar la clase del miércoles. 
Volviendo a tu branch:
```
 ~/ejercicio_biblioteca   resolucion_capurro 
 git checkout resolucion_fabian
Switched to branch 'resolucion_fabian'
```
No quiero alarmarte, pero tu bella modularización no está.
Quedó en el stash. Se puede recuperar fácilmente
```
 ~/ejercicio_biblioteca   resolucion_fabian 
 git stash pop
On branch resolucion_fabian
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

	modified:   primos_comandante.c

no changes added to commit (use "git add" and/or "git commit -a")
Dropped refs/stash@{0} (98e9e2818394416dabf0cc08d0f1906c96b1f901)
```

### Commits y guardar los cambios
Ahora, si estás conforme con la modularización, podés pasar a hacer un commit con los cambios.
Idealmente, se hace un commit cuando se cierra algún refactor (como es este caso) o se termina de implementar una nueva _feature_.
Sin embargo, es usual también hacer un commit para tener un punto al cual volver antes de intentar hacer algún cambio, incluso si es a mitad de una feature.
Recordando, un commit guarda los cambios en uno o mas archivos. Git cuenta con un área de _staging_, al crear un commit, se incluye en el todo lo que esté en ella. Se puede ignorar esta feature tranquilamente y agregar y commitear los archivos sin dedicarle muchas neuronas:
```
 ~/ejercicio_biblioteca   resolucion_fabian ● 
 git add primos_comandante.c 
 ~/ejercicio_biblioteca   resolucion_fabian ✚ 
 git commit -m "El programa ya no da ceguera y pasé a una función el chequeo de si un numero es primo"
[resolucion_fabian 006040e] El programa ya no da ceguera y pasé a una función el chequeo de si un numero no es primo
 1 file changed, 24 insertions(+), 23 deletions(-)
 rewrite primos_comandante.c (72%)
```
`-m` indica a git que el próximo argumento es el mensaje del commit.
Como con todo en la vida desde que decidieron cursar algoritmos 1, debe ser descriptivo.
Woo hoo! quedaron guardados los cambios en un commit, que podemos ver con `git log`:
```
 ~/ejercicio_biblioteca   resolucion_fabian 
 git log
commit 006040e5b383e9405d8cd153107248d764259e0d (HEAD -> resolucion_fabian)
Author: capurro <juanpcapurro@gmail.com>
Date:   Wed Oct 4 20:28:40 2017 -0300

    El programa ya no da ceguera y pasé a una función el chequeo de si un numero es primo

commit 81b4124ff32097f3d8309746d5cd354fb642fedb (origin/master, origin/HEAD, master)
Author: juanpcapurro <juanpcapurro@gmail.com>
Date:   Tue Oct 3 20:41:15 2017 -0300

    commit del cual comenzar la clase, el programa anda pero produce ceguera
(END)
```
Con esto ya estás armado para seguir con el trabajo en sucesivos commits en esta branch, ver la historia de la misma y chusmear qué se hizo en otras branches.

Tarea: 
* Refactorizar el código visto en una biblioteca, como se hizo en clase (básicamente, sacar la función `es_primo` a una biblioteca, y que el programa mantenga su funcionalidad).
* Hacer un commit con los cambios hechos, con un nombre descriptivo. Recordá que hay que agregar los archivos (`git add `) antes de ponerlos en un commit.

### Publicando a un repo remoto.

Ahora queda subir estos cambios a algún lado, para que alguien más pueda verlo o hacer cambios desde esta implementación, o simplemente para tener un backup en github.
Vas a poder hacer esto si forkeaste previamente el repositorio, y tenés un repo en github que es de tu propiedad.
Por qué es esto así? porque de otra forma estarías clonando _mi_ repo, y github no va a dejar que cualquier persona lo modifique.
Para _pushear_ tus cambios a github:
```
~/ejercicio_biblioteca   resolucion_fabian 
 git push origin resolucion_fabian
Counting objects: 6, done.
Delta compression using up to 4 threads.
Compressing objects: 100% (5/5), done.
Writing objects: 100% (6/6), 830 bytes | 830.00 KiB/s, done.
Total 6 (delta 1), reused 0 (delta 0)
remote: Resolving deltas: 100% (1/1), done.
To https://github.com/juanpcapurro/ejercicio_biblioteca.git
 * [new branch]      resolucion_fabian -> resolucion_fabian
```

## Merges

Es un buen momento para tomar un descanso y dejar asentar lo que vimos hasta ahora, ya que todo lo siguiente requiere tener bien claros los conceptos anteriores.

Ahora bien, hay un par de comandos y conceptos (ya vistos y nuevos) que hace falta explicar en más profundidad:
* `HEAD`: El último commit al que se le hizo checkout.
* `[commit]~n`: El n-ésimo ancestro de `commit`, siguiendo al primer padre en caso de ambigüedad. Se usa sin brackets. Ejemplos: `HEAD~1`, `branch_charly~2`.
* `git fetch`: Se comunica con _origin_, el repositorio remoto por defecto, y pregunta por nuevos cambios.
* `git merge branch_b`: Estando parado en el `branch_a`, se trae los cambios de `branch_b`. Hay tres tipos de merges posibles:
    * fast foward: Es el caso más facil, en el que el commit de destino (`branch_b` en este caso) es padre del commit actual, por lo que lo que se hace es avanzar (duh!) la referencia del branch actual. Si se quiere evitar esto a toda costa, y que se haga siempre un commit de merge, se puede pasarle `--no-ff` como parámetro, y así siempre generará un `merge commit`.
    * merge _feliz_: Se genera un _merge commit_, donde se explicita qué branches se mergearon, y como cualquier commit, se le puede agregar un mensaje. Al terminar el merge, se tienen los cambios de ambas branches.
    * _merge conflict_: Es el caso menos feliz, cuando en ambas branches se modificó el mismo archivo en la misma línea, y git no sabe qué cambio tomar como el verdadero.
    [Amerita cómics](https://xkcd.com/1597/). El repo queda en un estado de conflicto, y git espera que salgamos de este lío.
    Una opción posible es hacer `git merge --abort` para decirle a git 'al cabo que ni quería mergear', y desista en sus intentos, lo que deja el repo como estaba antes de intentar mergear.
    La otra opción es ver en qué archivos se dio el conflicto y resolverlo.
    Git escribe al archivo sobre el que está el conflicto, dejando marcas que indican cuales son los cambios de HEAD y cuales los de la branch a mergear.
    El conflicto se resuelve un haciendo un commit, que git tomará como válido sólo si se sacaron las marcas ya mencionadas. 
    La idea de este commit es que se decida qué versión (la de HEAD o la de la otra branch) va a quedar como definitiva, o bien se haga a mano un mergeo de las dos, pero es importante destacar que en esta etapa la única validación que hace git es verificar que se hayan sacado las marcas, no chequea que los cambios introducidos incluyan algo o nada de lo que se quería mergear, o que el código en cuestión sea correcto o vaya a compilar.
* `git pull`: Hace fetch del repo remoto y mergea los cambios de este con el último commit local de la branch actual, resultando, en los casos felices, en un fast-foward.
* `git push`: Hace fetch del repo remoto y le indica que haga un merge de su último commit del branch actual con el último local nuestro. Si no puede hacer fast-foward, falla. En tal caso, hay dos opciones:
    * Si la branch remota avanzó, y la local no: Hacer `git pull` para traer los cambios, y luego pushear.
    * Si la branch remota avanzó, y la local también 
