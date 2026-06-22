
x=3+1
y=4/2
numeric_vector<-c(TRUE,FALSE,TRUE,FALSE)
numeric_vector
#print(numeric_vector)
character_vector <-c("a", "b", "c", "d")
boolean_vector =c(5,6,7,8)


class(boolean_vector)

matrix(1:9, byrow = TRUE, nrow = 3)

# Matrices in R
matrix_data<-matrix(1:12, byrow = 12, nrow = 4)
colnames(matrix_data)<-c( "a", "b", "c")
rownames(matrix_data)<-c( "A", "B", "C", "D")

#rowsum, columsum, cbind rbind
matrix_data
colSums(matrix_data)
rowSums(matrix_data)
matrix_data
m1<-matrix(2:13, byrow = TRUE, nrow = 4)
m1
cbind(matrix_data, m1)
rbind(matrix_data, m1)

#Data Frame
vect1=c ("Ahmad", "Aliyu", "Uthman")
vect2=c (20, 30, 40)
vect3=c ("M", "M", "M")
vect1
vect2
vect3
myFrame=data.frame(vect1, vect2, vect3)
view(myFrame)

rownames(myFrame)<-c( "Person 1", "Person 2", "Person 3")
colnames(myFrame)<-c( "Name", "Age", "Gender")

#import and export













