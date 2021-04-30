#include <stdlib.h>
#include <unistd.h>

#undef NULL

#define NULL 0
#define EOF (-1)
#define BUFSIZ 8192
#define OPEN_MAX 20


typedef struct _iobuf {
	int cnt;
	char *ptr;
	char *base;
	int flag;
	int fd;
} FILE;
extern FILE _iob[OPEN_MAX];

#define stdin	(&_iob[0])
#define stdout	(&_iob[1])
#define stderr	(&_iob[2])

enum _flags {
	_READ	= 01,
	_WRITE	= 02,
	_UNBUF	= 04,
	_EOF	= 010,
	_ERR	= 020
};

int _myflush(FILE *fp);
int _myflushbuf(int x, FILE *fp);
int myfflush(FILE *fp);
int myfclose(FILE *fp);



int main(void)
{
    return 0;
}

int _myflushbuf(int x, FILE *fp)
{
    int bufsize;

    if ((fp->flag & (_WRITE | _ERR)) != _WRITE)
        return EOF;
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    if (fp->base == NULL) {
        if ((fp->base = malloc(bufsize)) == NULL)
            return EOF;
    } else if (write(fp->fd, fp->base, bufsize) != bufsize) {
        fp->flag |= _ERR;
        fp->cnt = 0;
        return EOF;
    }

    fp->ptr = fp->base;
    fp->cnt = bufsize;

    --fp->cnt;
    return (unsigned char)(*fp->ptr++ = x);
}

int myfflush(FILE *fp)
{
    if (fp != NULL) {
        if (fp->flag & _ERR)
            return EOF;
        if ((fp->flag & _WRITE) && fp->base != NULL)
            return _myflush(fp);
        
        return 0;
    } else {
        int r, i;

        r = 0;
        for (i = 0; i < OPEN_MAX; i++)
            if ((_iob[i].flag & (_WRITE | _ERR)) == _WRITE
            && _iob[i].base != NULL
            && _myflush(&_iob[i]) == EOF)
                r = EOF;
        
        return r;
    }
}   

int myfclose(FILE *fp)
{
    int r;

    r = 0;
    if (fp->flag & _WRITE)
        r = myfflush(fp);

    if (fp->base != NULL)
        free(fp->base);

    fp->flag = 0;

    return close(fp->fd) == -1 ? EOF : r;
}

int _myflush(FILE *fp)
{
    if (write(fp->fd, fp->base, fp->ptr - fp->base) !=  fp->ptr - fp->base) {
            fp->flag |= _ERR;
            fp->cnt = 0;
            return EOF;
    } else {
            fp->ptr = fp->base;
            fp->cnt = fp->flag & _UNBUF ? 0 : BUFSIZ;
            return 0;
    }
}