import graphics

m = graphics.Mesh()
a,b,c = (m.add_vertex(),m.add_vertex(),m.add_vertex())
t = m.add_triangle(a,b,c)
a.id = 1
print( a.id )