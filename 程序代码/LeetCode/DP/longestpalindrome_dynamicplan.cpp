/******最长回文子串******
LONGEST-PALINDROME(s)
n=s.length
if n==0 || n==1
   return s

let m[1...n,1..n],w[1...n,1..n] be new tables
for i=1 to n
    m[i,i]=1
    w[i,i]=i
for i=1 to n-1
    if s(i)==s(i+1)
       m[i,i+1]=2
       w[i,i]=i
    else
       m[i,i+1]=1;
       w[i,i+1]=i

//遍历所有的奇数项
for i=1 to n
    p=i
    q=i
    l=1
    while p>0 && q<n+1
        if (s(p-1)!=s(q+1))
            m[p,q]=l
            w[p,q]=p
            for j=p-1 to 1
                k=2*i-j
                if k<n+1
                   m[j,k]=l
                   w[j,k]=p
        else
            p=p-1
            q=q+1
            l=l+2
            m[p,q]=l
            w[p,q]=p

//遍历所有的偶数项，只需在遍历奇数的基础上改动下q和l即可
for i=1 to n-1
    p=i
    q=i+1
    l=2
    while p>0 && q<n+1
        if (s(p-1)!=s(q+1))
            m[p,q]=l
            w[p,q]=p
            for j=p-1 to 1
                k=2*i-j
                if k<n+1
                   m[j,k]=l
                   w[j,k]=p
        else
            p=p-1
            q=q+1
            l=l+2
            m[p,q]=l
            w[p,q]=p
******最长回文子串******/