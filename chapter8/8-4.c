// copy from https://github.com/anotherlin/tcpl/blob/master/chapter_8/exercise_8-4.c
// I edited a typo
// 		while (n--) {
// 			*fp->ptr++ = 0; 
//			fp->cnt--;  // this line was originally fp->cnt++;      
// 		}


int fseek (FILE *fp, long offset, int whence)
{
	long curpos, newpos;

    if ((fp->flag & _ERR) 
	|| (!(fp->flag & _READ) && !(fp->flag & _WRITE)))
        return -1;

	curpos = fp->bufpos + (fp->base != NULL ? fp->ptr - fp->base : 0);

	if (whence == SEEK_SET)
        newpos = offset;
    else if (whence == SEEK_CUR)
        newpos = curpos + offset;
    else {	/* SEEK_END */
        if ((newpos = lseek(fp->fd, 0, SEEK_END)) == -1
		|| lseek(fp->fd, fp->bufpos, SEEK_SET) == -1) {
            fp->flag |= _ERR;
			fp->cnt = 0;
			return -1;
        }
		newpos += offset;
    }

    if (fp->flag & _UNBUF)
        fp->bufpos = newpos;
    else if (fp->flag & _READ) {
        if (fp->base == NULL)
            fp->bufpos = newpos;
        else if (newpos < fp->bufpos || newpos >= curpos + fp->cnt) {
            fp->ptr = fp->base;
			fp->cnt = 0;
			fp->bufpos = newpos;
        } else {
            fp->ptr = fp->base + newpos - fp->bufpos;
			fp->cnt -= newpos - curpos;
        }
    } else {
        if (fp->base == NULL)
            fp->bufpos = newpos;
        else if (newpos < curpos || newpos >= fp->bufpos + BUFSIZ) {
            _flush(fp);
			fp->bufpos = newpos;
        } else {
            long n;

			n = newpos - curpos; 
			while (n--) {
                *fp->ptr++ = 0; 
				fp->cnt--;      
            }
        }
    }
	
	if (lseek(fp->fd, fp->bufpos, SEEK_SET) == -1) {
        fp->flag |= _ERR;
		fp->cnt = 0;
		return -1;
    } else
        return 0;
}