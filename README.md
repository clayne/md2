# MD2 hash function in ANSI C

This is a simple implementation of MD2 as an ANSI C header library. It
follows the specification in [RFC 1319][rfc].

```c
void md2_init(struct md2 *);
void md2_append(struct md2 *, const void *, size_t);
void md2_finish(struct md2 *, void *);
```

[rfc]: https://tools.ietf.org/html/rfc1319
