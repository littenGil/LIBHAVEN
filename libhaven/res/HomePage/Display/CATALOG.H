#ifndef HOMEPAGE_CATALOG_H
#define HOMEPAGE_CATALOG_H

int updatecatalog(int offset, int *nbooks, char catalog[12][7], char search[35])
{
    //Variables
    FILE *booklist = fopen("c:/libhaven/books/list.txt", "r");
    FILE *book;
    int i;    
    char bookid[7], title[37]={0}, bookpath[37], borrower[37];
    //Clear Catalog and Reset nBooks
    memset(catalog,0,sizeof(catalog));
    (*nbooks)=0;
    
    //Move to offset (count only items that matches searched word)
    for(i=0; i<offset; i++)
    {
      if(!fscanf(booklist, " %6s", bookid)){fclose(booklist);return 0;};
      memset(title,0,sizeof(title));
      sprintf(bookpath, "c:/libhaven/books/%s.txt", bookid);
      book = fopen(bookpath, "r");
      fscanf(book, " %35s", title);
      fclose(book);
      if (!checksubstring(bookid, bookSearch) || !checksubstring(title, bookSearch)){i--;continue;};
      sprintf(bookpath, "c:/libhaven/lost/%s.txt", bookid);
      book = fopen(bookpath, "r");
      fscanf(book, " %35[^\n]s", title);
      fclose(book);
      if (!checksubstring(title, bookSearch)){i--;continue;};
    }
    
    //Fill the catalog with at most 12 books (include only the searched item)
    while (fscanf(booklist, " %6s", bookid) == 1)
    {
      memset(title,0,sizeof(title));
      sprintf(bookpath, "c:/libhaven/books/%s.txt", bookid);
      book = fopen(bookpath, "r");
      fscanf(book, " %35[^\n]s", title);
      fclose(book);
      memset(borrower,0,sizeof(borrower));
      sprintf(bookpath, "c:/libhaven/borrowed/%s.txt", bookid);
      book = fopen(bookpath, "r");
      fscanf(book, " %35[^\n]s", borrower);
      fclose(book);
	  if (checksubstring(bookid, search) || checksubstring(title, search)||checksubstring(borrower, bookSearch))
	  {
	    strcpy(catalog[(*nbooks)++], bookid);
	  }
      if((*nbooks)>=12){break;};
    }
    
    //Check if there are more book matches for next page
    if(fscanf(booklist, " %6s", bookid) == 1){fclose(booklist);return 1;}
    else{fclose(booklist);return 0;}
}



#endif