### Реализация на С++

* [SearchTree.h](https://github.com/grifguitar/itmo-circle-B.dist/tree/main/lecture_search_tree/SearchTree.h)
* [SearchTree.cpp](https://github.com/grifguitar/itmo-circle-B.dist/tree/main/lecture_search_tree/SearchTree.cpp)

### Запуск

Пример декартового дерева для элементов:

`-64 -51 -36 -23 -15 -13 12 70 84 95 2147483647`

Вершины дерева изображены в формате `[value, priority]`:

```haskell
(
    (
        (
        *
        [-64, 49]
            (
            *
            [-51, -97]
            *
            )
        )
    [-36, 83]
        (
        *
        [-23, -83]
        *
        )
    )
[-15, 96]
    (
    *
    [-13, 70]
        (
            (
                (
                *
                [12, -36]
                *
                )
            [70, 25]
                (
                *
                [84, -48]
                *
                )
            )
        [95, 37]
            (
            *
            [2147483647, 34]
            *
            )
        )
    )
)
```
