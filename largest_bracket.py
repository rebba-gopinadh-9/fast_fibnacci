s=input()
prev,curr,next=0,0,0
top=0
count=0
for i in s:
    if i=="(":
        top+=1
    if i==")":
        top-=1
        next+=1
        if curr<next:
            curr=next
        if top==0 and curr==next:
            if curr>prev:
                count=0
                prev=curr
            count+=1
            next=0

print("The largest bracket is :",2*curr,"The number of largrest brackets :",count)
