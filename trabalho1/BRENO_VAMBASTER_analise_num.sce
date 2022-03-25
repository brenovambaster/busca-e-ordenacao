/*
BRENO VAMBÁSTER CARDOSO LIMA
CIE. COMPUTAÇÃO, IFNMG
ANÁLISE NUMÉRICA - PROF TATI
22/02022 

Solução de sistemas de equações tridiagonais
*/

function x = Tridiagonal(e,f,g,r)
/*
INPUT:
vet_subdi = vetor subdiagonal
vet_diag = vetor diagonal
vet_superdiag = vetor superdiagonal
vet_direito = vetor do lado direito
   
OUTPUT:
x = vetor solução
   
*/

tam_vet_diag=length(vet_diag);
//eliminação progressiva
for k = 2:tam_vet_diag
 factor = vet_subdi(k)/vet_diag(k-1);
 vet_diag(k) = vet_diag(k) - factor*vet_superdiag(k-1);
 vet_direito(k) = vet_direito(k) - fator*vet_direito(k-1);
end

//substituição regressiva
x(tam_vet_diag) = vet_direito(tam_vet_diag)/vet_diag(tam_vet_diag);
for k = tam_vet_diag-1:-1:1
 x(k) = (vet_direito(k)- vet_superdiag(k)*x(k+1))/vet_diag(k);
end
end function