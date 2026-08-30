class Solution:
    def isValid(self, s: str) -> bool:

        #hindhagade open idre mathe idhu open idre add madi 
        #hindagade close idre idhu open idre return false
        #stack ali inna idre return false

       

        st = []

        for i in s:
            if i == '{' or i=='(' or i=='[':
                st.append(i)
            elif not st:
                return False
            elif st[-1] == '(' and (i== '}' or i ==  ']') :
                return False
            elif st[-1] == '{' and (i == ']' or i == ')'):
                return False
            elif st[-1] == '[' and (i == ')' or i == '}'):
                return False
            elif (st[-1] == '{' and i == '}') or (st[-1] == '(' and i == ')') or (st[-1] == '[' and i == ']'):
                st.pop()
        return len(st) == 0
            
                

        