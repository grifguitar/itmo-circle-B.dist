### Реализация на С++

* [SearchTree.h](https://github.com/grifguitar/itmo-circle-B.dist/tree/main/lecture_search_tree/SearchTree.h)
* [SearchTree.cpp](https://github.com/grifguitar/itmo-circle-B.dist/tree/main/lecture_search_tree/SearchTree.cpp)

### Запуск

Пример декартового дерева для элементов:

`-98 -69 -45 -16 43 53 54 56 95 100 2147483647`

Вершины дерева изображены в формате `[value, priority]`:

```haskell
(
    (
        (
            (
            -
            [-98, -15]
            -
            )
        [-69, 17]
        -
        )
    [-45, 17]
    -
    )
[-16, 90]
    (
        (
        -
        [43, -66]
            (
            -
            [53, -67]
                (
                -
                [54, -70]
                -
                )
            )
        )
    [56, 31]
        (
            (
            -
            [95, -17]
            -
            )
        [100, 9]
            (
            -
            [2147483647, -79]
            -
            )
        )
    )
)
```
