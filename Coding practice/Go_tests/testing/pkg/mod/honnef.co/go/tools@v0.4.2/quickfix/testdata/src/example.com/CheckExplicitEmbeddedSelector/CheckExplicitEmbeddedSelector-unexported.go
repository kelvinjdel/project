package pkg

type UnexportedSamePackageOuter struct {
	unexportedSamePackageInner
}

type unexportedSamePackageInner struct {
	F10 int
}

func fnUnexported() {
	var unexportedSame UnexportedSamePackageOuter
	_ = unexportedSame.unexportedSamePackageInner.F10 //@ diag(`could remove embedded field "unexportedSamePackageInner" from selector`)
	_ = unexportedSame.F10                            // minimal form
}
