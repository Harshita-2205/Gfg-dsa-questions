class Solution:
    def dfs(self,ans,image,r,c,newColor,delr,delc,initial):
        n=len(image)
		m=len(image[0])
		ans[r][c]=newColor
		for i in range(4):
		    nr = r+delr[i]
		    nc = c+delc[i]
		    if(0<=nr<n and 0<=nc<m and image[nr][nc]==initial and ans[nr][nc]!=newColor):
		        
		        self.dfs(ans,image,nr,nc,newColor,delr,delc,initial)
        
	def floodFill(self, image, sr, sc, newColor):
		#Code here0
		n=len(image)
		m=len(image[0])
		initial = image[sr][sc]
		ans=image
		delr = [-1,0,+1,0]
		delc = [0,+1,0,-1]
		self.dfs(ans,image,sr,sc,newColor,delr,delc,initial)
		return ans
		
		
