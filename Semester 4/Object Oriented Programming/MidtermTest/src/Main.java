import java.util.ArrayList;

class Author {
    private String name;
    private String nationality;

    public Author(String name, String nationality){
        this.name = name;
        this.nationality = nationality;
    }
    public String getName(){
        return name; 
    }
    public String getNationality(){
        return nationality; 
    }
}

class Book {
    private String title;
    private int year;
    private Author author; // Aggregation

    public Book(String title, int year, Author author){
        this.title = title;
        this.year = year;
        this.author = author;
    }

    public void printBookInfo(){
        System.out.println("Title: " + title);
        System.out.println("Year Published: " + year);
        System.out.println("Author: " + author.getName());
        System.out.println("Nationality: " + author.getNationality()); 
    }
}

class Library {
   private String name;
   private ArrayList<Book> books;
   private Librarian librarian; // Composition

   public Library(String name, String librarianName, int librarianId){
        this.name = name;
        librarian = new Librarian(librarianName, librarianId);
        books = new ArrayList<>();
   }

    public void addBook(Book book){
        books.add(book);
   }

   public void removeBook(Book book){

        books.remove(book);
   }
   public void printLibraryInfo(){
      System.out.println("Library Name: " + name);
      System.out.println("Librarian Name: " + librarian.getName());
      System.out.println("Librarian ID: " + librarian.getId() + "\n");
      
      System.out.println("Books in the Library: ");
      for (int i = 0; i < books.size(); i++) {
        System.out.println("Book #" + (i+1) + " :");
        books.get(i).printBookInfo(); 
        System.out.println();
      }
   }
}

class Librarian {
    private String name;
    private int id;

    public Librarian(String name, int id){
        this.name  = name;
        this.id = id;
    }

    public String getName(){
        return name;
    }

    public int getId(){
        return id;
    }
}


public class Main {
    public static void main(String[] args){
        Author author1 = new Author("J.K. Rowling", "British");
        Author author2 = new Author("Stephen King", "American");
        Author author3 = new Author("George Orwell", "Irish");

        Book book1 = new Book("Harry Potter and the Philosopher's Stone", 1997, author1);
        Book book2 = new Book("The Shining", 1977, author2);
        Book book3 = new Book("1984", 1949, author3);

        Library library = new Library("Dewan Bahasa dan Pustaka", "Lisa", 12345);
        library.addBook(book1);
        library.addBook(book2);
        library.addBook(book3);

        library.printLibraryInfo();

        library.removeBook(book2);
        System.out.println("\nAfter removing book2:");
        library.printLibraryInfo();
    }
}
